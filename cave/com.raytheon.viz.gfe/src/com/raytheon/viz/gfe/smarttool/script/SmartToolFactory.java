/**
 * This software was developed and / or modified by Raytheon Company,
 * pursuant to Contract DG133W-05-CQ-1067 with the US Government.
 * 
 * U.S. EXPORT CONTROLLED TECHNICAL DATA
 * This software product contains export-restricted data whose
 * export/transfer/disclosure is restricted by U.S. law. Dissemination
 * to non-U.S. persons whether in the United States or abroad requires
 * an export license or other authorization.
 * 
 * Contractor Name:        Raytheon Company
 * Contractor Address:     6825 Pine Street, Suite 340
 *                         Mail Stop B8
 *                         Omaha, NE 68106
 *                         402.291.0100
 * 
 * See the AWIPS II Master Rights File ("Master Rights File.pdf") for
 * further licensing information.
 **/
package com.raytheon.viz.gfe.smarttool.script;

import jep.JepException;

import com.raytheon.uf.common.dataplugin.gfe.python.GfePyIncludeUtil;
import com.raytheon.uf.common.localization.LocalizationContext;
import com.raytheon.uf.common.localization.LocalizationContext.LocalizationLevel;
import com.raytheon.uf.common.localization.LocalizationContext.LocalizationType;
import com.raytheon.uf.common.localization.PathManagerFactory;
import com.raytheon.uf.common.python.PyUtil;
import com.raytheon.uf.common.python.PythonIncludePathUtil;
import com.raytheon.uf.common.util.FileUtil;
import com.raytheon.viz.gfe.core.DataManager;

/**
 * Factory for smart tools
 * 
 * <pre>
 * SOFTWARE HISTORY
 * Date         Ticket#     Engineer    Description
 * ------------ ----------  ----------- --------------------------
 * Mar 21, 2008             njensen	    Initial creation
 * Jul 9, 2009    2454      ryu         Put user and site's python scripts on path for import
 * May 20, 2015   4509      njensen     Added time and dataaccess to include path
 * Jul 23, 2015   4263      dgilling    Refactored to support changes to SmartToolController.
 * 
 * </pre>
 * 
 * @author njensen
 * @version 1.0
 */

public class SmartToolFactory {

    private static String getScriptPath() {
        LocalizationContext baseCtx = PathManagerFactory.getPathManager()
                .getContext(LocalizationType.CAVE_STATIC,
                        LocalizationLevel.BASE);
        String scriptPath = GfePyIncludeUtil.getUtilitiesLF(baseCtx).getFile()
                .getPath();
        return FileUtil.join(scriptPath, "SmartToolInterface.py");
    }

    private static String getIncludePath() {
        return PyUtil.buildJepIncludePath(PythonIncludePathUtil
                .getCommonPythonIncludePath("time", "dataaccess"),
                GfePyIncludeUtil.getVtecIncludePath(), GfePyIncludeUtil
                        .getCommonGfeIncludePath(), GfePyIncludeUtil
                        .getSmartToolsIncludePath(), GfePyIncludeUtil
                        .getUtilitiesIncludePath());
    }

    private static SmartToolController buildInstance(DataManager dataMgr,
            boolean ui) throws JepException {
        SmartToolController smartCont = null;
        if (ui) {
            smartCont = new SmartToolMetadataScriptFactory(dataMgr)
                    .createPythonScript();
        } else {
            smartCont = new SmartToolRunnerController(getScriptPath(),
                    getIncludePath(), SmartToolFactory.class.getClassLoader(),
                    dataMgr);
        }

        return smartCont;
    }

    public static SmartToolRunnerController buildController(DataManager dataMgr)
            throws JepException {
        return (SmartToolRunnerController) buildInstance(dataMgr, false);
    }

    public static SmartToolMetadataController buildUIController(
            DataManager dataMgr) throws JepException {
        return (SmartToolMetadataController) buildInstance(dataMgr, true);
    }
}
