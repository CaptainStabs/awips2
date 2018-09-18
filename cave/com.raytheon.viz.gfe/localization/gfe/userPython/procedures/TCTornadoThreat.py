# ----------------------------------------------------------------------------
#
# This software is in the public domain, furnished "as is", without technical
# support, and with no warranty, express or implied, as to its usefulness for
# any purpose.
#
# TornadoFloodThreat
#
# Author: Tom LeFebvre/Pablo Santos
# Updated: April 16, 2012 to lower Low Category Threshold and hide Sliding Bars
# Migrated procedure for AWIPS2. Updated 6/22/2012.  S.O.
# Sept 19, 2014: Updated Low to Elevated for 2015 Official Implementation. PS
# Modified: By Belk 07/15/2016 to make efficiency improvements, and 
#   refactor to make use of a utility containing common methods with other tools
# Modified: By LeFebvre 09/23/2016 finish converstion to numpy conventions. 
# CHECKED IN for 17.1.1
#
# Modified: By LeFebvre 06/12/17 - Fixed bug that incremented TornadoThreat
# beyond Extreme and caused a crash.
# ----------------------------------------------------------------------------

##
# This is an absolute override file, indicating that a higher priority version
# of the file will completely replace a lower priority version of the file.
##

# The MenuItems list defines the GFE menu item(s) under which the
# Procedure is to appear.
# Possible items are: Populate, Edit, Consistency, Verify, Hazards
MenuItems = ["Populate"]

import TropicalUtility
import time
import sys
import AbsTime
import TimeRange
import numpy as np

VariableList = [("NOTE: Day 1 Tornado Probabilities Used by Procedure:", "", "label"),
                #("Very Low" , "02", "radio", ["02"]),
                ("Elevated" , "02", "radio", ["02"]),
                ("Mod" ,"15", "radio", ["15"]),
                ("High","30", "radio", ["30"]),
                ("Extreme" ,"45", "radio", ["45"]),
                ("Day 2: Prob Svr Wx (ptotsvr) >= 5: Elevated; ptotsvr >= 60%: Mod", "", "label"),
                ("Day 2: Prob Sig Svr Wx (ptotxsvr) >= 10: Elevated -> Mod and Mod -> High", "", "label"),
                ("Day 3: Prob Svr Wx (ptotsvr) >= 5: Elevated", "", "label"),
                ("Day 3: Prob Sig Svr Wx (ptotxsvr) >= 10: Elevated -> Mod", "", "label"),
                ("NOTE: After applying logic above", "", "label"),
                ("threat level is the max composite from Day 1-3", "", "label")               
                ]


class Procedure (TropicalUtility.TropicalUtility):
    def __init__(self, dbss):
        TropicalUtility.TropicalUtility.__init__(self, dbss)


    def variableExists(self, modelName, weName, weLevel):

        # it turns out the the modelName will not match the dbID().model()
        # directly, so it needs to be massaged a bit.
        parts = modelName.split("_")
        if len(parts) >= 4:
            modelName = parts[3]
            
        availParms = self.availableParms()    
        for pName, level, dbID in availParms:
            if dbID.modelName().find(modelName) > -1:
                if pName.find(weName) > -1 and level.find(weLevel) > -1:
                    return True

        return False

    def getWEInventory(self, modelName, WEName, timeRange = None):

        allTimes = TimeRange.allTimes()
        
        if timeRange is None:
            timeRange = allTimes

        weLevel = "SFC"

        if not self.variableExists(modelName, WEName, weLevel):
            #print WEName, "does not exist in model", modelName
            return []

        try:
            gridInfo = self.getGridInfo(modelName, WEName, weLevel, timeRange)
        except:
            #print "GridInfo failed for:", modelName, WEName, weLevel, timeRange
            return []

        trList = []
        for g in gridInfo:
            start = g.gridTime().startTime().unixTime()
            end = g.gridTime().endTime().unixTime()
            tr = self.GM_makeTimeRange(start, end)
            if timeRange.overlaps(tr):
                trList.append(tr)

        return trList    

    # get the current time, truncates to the last six hour value.
    # returns a timeRange with this startTime until 24 hrs from this time
    def make6hrTimeRange(self):
        startTime = int(self._gmtime().unixTime()/ (3600 * 6)) * 3600 * 6
        endTime = startTime + (3600 * 6)
        
        timeRange = self.GM_makeTimeRange(startTime, endTime)

        return timeRange

    # Returns a list of dbIdentifiers that match the specified model
    # name, weName and level.
    def getModelList(self, modelName, weName, weLevel):
        modelList = []

        availParms = self.availableParms()

        for pName, level, dbID in availParms:
            if dbID.modelName().find(modelName) > -1:
                if pName.find(weName) > -1:
                    if level.find(weLevel) > -1:
                        if dbID.modelIdentifier() not in modelList:   
                            modelList.append(dbID.modelIdentifier())
        return modelList

    def determineDay(self, modelTime, validTime):

        diff = (validTime - modelTime) / 3600
        if diff < 36:
            return 1
        elif diff >= 36 and diff < 60:
            return 2
        elif  diff >= 60:
            return 3

        return 0

    # returns a unix time based on the specified model ID.
    def getModelTime(self, modelName):

        timeStr = modelName[-13:]

        year = int(timeStr[0:4])
        month = int(timeStr[4:6])
        day = int(timeStr[6:8])
        hour = int(timeStr[9:11])

        absTime = AbsTime.absTimeYMD(year, month, day, hour, 0, 0)
        absTime = AbsTime.absTimeYMD(year, month, day, hour, 0, 0)
        
        return absTime.unixTime()

    def getTornadoGrid(self, varName, dayNum):
        siteID = self.getSiteID()
        SPCModelName = siteID + "_D2D_SPC"
        SPCVarName = varName
        SPCLevel = "SFC"

        modelList = self.getModelList("SPC", SPCVarName, SPCLevel)
        #print "Processing varName, dayNum: ", varName, dayNum

        hours24 = 24 * 3600

        for modelName in modelList:

            trList = self.getWEInventory(modelName, SPCVarName)
            #print "modelName trList:", modelName, trList
            if len(trList) == 0:   # no grids found for this version
                continue   # go on to older versions

            modelTime = self.getModelTime(modelName)
            # get the current time rounded to the nearest 12Z
            currentTime = (int(time.time() / hours24) * hours24) + (12 * 3600)

            for tr in trList:
                gridDayNum = self.determineDay(currentTime,
                                               tr.startTime().unixTime())
                #print "modelName, modelTime, and gridDayNum:", modelName, modelTime, gridDayNum
                if gridDayNum == dayNum:
                    grid = self.getGrids(modelName, SPCVarName, SPCLevel, tr)
                    return grid

        return None

    # This method adjusts an existing threat grid
    def adjustTornadoGrid(self, tornadoThreat, threatKeys, var, dayNum, extThreshold):
        D2DGrid = self.getTornadoGrid(var, dayNum)
        if D2DGrid is None:
            #print "No grid found for", var, "day:", dayNum
            return tornadoThreat

        # Account for offices using the four key arrangement
        # Just change the "Very Low" to "Low" in the threshDict
        #if "Very Low" not in threatKeys:
        #    # find all places greater than "Very Low or Low" in the tornadoThreat
        #    lowIndex = self.getIndex("Low", threatKeys)
        #else:
        #    lowIndex = self.getIndex("Very Low", threatKeys)
        #lowMask = greater_equal(tornadoThreat, lowIndex)

#        lowMask = greater(tornadoThreat, 0)
        lowMask = tornadoThreat > 0

        # finds all places in the extreme grid >= to the extThreshold
#        xMask = greater_equal(D2DGrid, extThreshold)
        xMask = D2DGrid >= extThreshold

        # increment the threat where these masks intersect
        mask = lowMask & xMask

        # make sure we're not incrementing too far
        extremeIndex = self.getIndex("Extreme", threatKeys)

        # increment the category.  This code assumes that the categories are
        # defined in increasing order of severity.
        tornadoThreat[mask] +=  1

        # Clip the adjusted grid to the maximum allowed value - extremeIndex
        tornadoThreat = np.clip(tornadoThreat, 0, extremeIndex)

        return tornadoThreat


    def setTornadoGrid(self, tornadoThreat, threatKeys, var, dayNum, threshDict):

        D2DGrid = self.getTornadoGrid(var, dayNum)
        if D2DGrid is None:
            #print "No grid found for", var, "day:", dayNum
            return tornadoThreat

        # Account for offices using the four key arrangement
        # Just change the "Very Low" to "Low" in the threshDict
        #print "THREATKEYS ARE: ", threatKeys
        #print "THRESHDICT IS: ", threshDict.keys()       
        if "Very Low" not in threatKeys:
            for key in list(threshDict.keys()):
                if threshDict[key] == "Very Low":
                    threshDict[key] = "Elevated"
        dictKeys = list(threshDict.keys())
            
        #print "unsorted dictKeys: ", dictKeys
        dictKeys.sort()  # sort lowest to highest value
        #print "sorted dictKeys: ", dictKeys
       

        # Set the grid values based on the tornado prob grid and thresholds
        for key in dictKeys:
            thresh = int(key)
            #print "THRESH IS: ", thresh
            keyIndex = self.getIndex(threshDict[key], threatKeys)
            # make a temp grid where the thresholds are exceeded
            tempGrid = self.empty(dtype=np.int8)
            tempGrid[D2DGrid >= thresh] =  keyIndex
            # calculate areas where this temp grid exceeds the threatGrid
            mask = tempGrid > tornadoThreat
            # update the threatGrid for these areas only
            tornadoThreat[mask] = keyIndex

        return tornadoThreat
                    
    def execute(self, varDict):

        threatWEName = "TornadoThreat"
        
        threatKeys = self.getDiscreteKeys(threatWEName)
       
        # make a dict to store thresholds from the UI
        ptorDict = {}

        for key in threatKeys:
            if key == "None":
                continue
            ptorDict[varDict[key]] = key

        #print "***************************"
        #print "ptorDict is:", ptorDict
        #print "***************************"

        # Set up the data for processing the various grids.
        # Each entry consists of the D2D variable to be checked,
        # the day number of that grid, and a dictionary that defines
        # each threshold value and the corresponding discrete value.
        # Note the grids will be processed in the order defined in
        # this list.
        actionList = [
            ("ptor", 1, ptorDict, "sigtrndprob", 10),  # ptorDict comes from the GUI
            
            ("prsvr", 2, { 5 : "Very Low",
                            #15 : "Elevated",
                             5 : "Elevated",
                            60 : "Mod",
                           },
                            "prsigsv", 10),

            ("prsvr", 3, { 5 : "Very Low",
                            #15 : "Elevated",
                             5 : "Elevated",
                             
                           },
                            "prsigsv", 10),

                    ]

         # make a grid of zeros.  This will be the TornadoThreat grid
        tornadoThreat = self.empty(dtype=np.int8)

        for var, dayNum, threshDict, xVar, xThreshold in actionList:
            tornadoThreat = self.setTornadoGrid(tornadoThreat, threatKeys,
                                                var, dayNum, threshDict)

            # now adjust the grid based on the extreme grid category
            tornadoThreat = self.adjustTornadoGrid(tornadoThreat, threatKeys,
                                                   xVar, dayNum, xThreshold)

        # make a timeRange - 6 hours long, rounded to nearest hour
        startTime = int(self._gmtime().unixTime()/ 3600) * 3600
        endTime = startTime + (6 * 3600)
        threatTR = self.GM_makeTimeRange(startTime, endTime)

        # remove any old grids that are lying around
        startTime = int(self._gmtime().unixTime()/ 3600) * 3600 - (24 * 3600)
        endTime = startTime + (24 * 3600 * 10)
        removeTR = self.GM_makeTimeRange(startTime, endTime)
        self.deleteCmd([threatWEName], removeTR)

        # create the TornadoThreat Grid
        self.createGrid("Fcst", threatWEName, "DISCRETE",
                        (tornadoThreat, threatKeys), threatTR,
                        discreteKeys=threatKeys,
                        discreteOverlap=0,
                        discreteAuxDataLength=2,
                        defaultColorTable="Hazards")

        return


