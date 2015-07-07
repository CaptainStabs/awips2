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
package com.raytheon.uf.edex.plugin.redbook.menu;

import com.raytheon.uf.common.localization.IPathManager;
import com.raytheon.uf.common.status.IUFStatusHandler;
import com.raytheon.uf.common.status.UFStatus;

/**
 * Builds the NCEP/Hydro HPC menu contributions for NDM (Redbook HPC).
 * 
 * <pre>
 * 
 * SOFTWARE HISTORY
 * 
 * Date         Ticket#    Engineer    Description
 * ------------ ---------- ----------- --------------------------
 * Mar 12, 2014   2855     mpduff      Initial creation.
 * Jun 26, 2015    4512    mapeters    Abstract out createMenusFromFile()
 * 
 * </pre>
 * 
 * @author mpduff
 * @version 1.0
 */

public class RedbookHpcMenuUtil extends RedbookMenuUtil {
    /** Status handler */
    private static final IUFStatusHandler statusHandler = UFStatus
            .getHandler(RedbookHpcMenuUtil.class);

    /** Menu type constant */
    private static final String MENU_TYPE = NCEP_HYDRO + IPathManager.SEPARATOR
            + "hpc";

    /** HPC menu file */
    private static final String HPC_MENU = "hpcMenus.xml";

    /** HPC menu file full path */
    private static final String MENU_FILE = MENUS + IPathManager.SEPARATOR
            + MENU_TYPE + IPathManager.SEPARATOR + HPC_MENU;

    /**
     * Constructor.
     */
    public RedbookHpcMenuUtil() {
        super();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void createMenus() {
        statusHandler.info("Creating menus for " + MENU_FILE);
        createMenusForFile(MENU_FILE);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    protected boolean checkCreated() {
        return super.checkCreated(HPC_MENU, MENU_TYPE);
    }
}