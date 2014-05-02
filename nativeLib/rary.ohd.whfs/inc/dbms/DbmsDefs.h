/***************************************************************************
**
**	File:		DbmsDefs.h
**	Purpose:	Provides length definitions for the IHFS_DB
**			database table fields.
**
**
***************************************************************************/

#ifndef DBMS_DEFS_H
#define DBMS_DEFS_H

#define BOOL_LEN		1
#define CODE_LEN		1
#define LONG_CODE_LEN		6
#define LAT_LON_LEN		9
#define SHORT_LEN		80
#define LONG_LEN		255

#define	ADDR_LEN		24
#define AGENCY_OFFICE_NAME_LEN	64
#define APP_NAME_LEN            20
#define AREA_ID_LEN             10
#define	BACKWATER_LEN		8
#define BASIN_ID_LEN		LOC_ID_LEN
#define	BENCH_NUM_LEN		6
#define BOUNDARY_TYPE_LEN       6
#define CD_ORDER_LEN		4
#define CD_PREFIX_LEN		8
#define CITY_LEN		30
#define	CITY_NAME_LEN		20
#define COGRP_ID_LEN		8
#define COLOR_NAME_LEN          25
#define COLOR_USE_NAME_LEN      15
#define COMP_METH_LEN           30
#define CONTACT_LEN		28
#define COUNTY_LEN		20
#define CPM_LEN			3
#define CREST_DESC_LEN		SHORT_LEN
#define CREST_PRINT_LEN		BOOL_LEN
#define CRIT_LEN		50
#define CUSTOMER_LEN            80
#define DAM_ID_NUM_LEN		5
#define DAM_NAME_LEN		40
#define DATA_TYPE_LEN		4
#define DATA_TYPE_NAME_LEN	32
#define DATE_LEN		10
#define DB_DESCR_LEN		18
#define DESCRIP_LEN		60
#define DESC_LEN		30
#define DISP_STMT_LEN		60
#define DOUBLE_REMK_LEN		512
#define OBS_EMAIL_LEN           60
#define ESP_FCST_LEN		20
#define	EXTAGENCY_LEN		8
#define FCGRP_ID_LEN 		8
#define FCST_HORIZON_LEN	30
#define FCST_METHOD_LEN		30
#define FCST_TYPE_LEN		5
#define FILE_NAME_LEN		20
#define FLOW_TYPE_LEN           40
#define FREQ_UPDATE_LEN         30
#define GAGE_MAINT_LEN		10
#define GAGE_NUM_LEN		10
#define GAGE_OWNER_LEN		10
#define GEOLINE_NAME_LEN	20
#define GOES_ID_LEN		8
#define GROUP_NAME_LEN		32
#define HI_WATER_LEN		BOOL_LEN
#define HORIZ_DATUM_LEN		9
#define HYD_SERV_LEN		3
#define HYD_UNIT_LEN		8
#define ICE_INFO_LEN		160
#define ICE_JAM_LEN		BOOL_LEN
#define IMAGE_ID_LEN            10
#define IMAGE_TITLE_LEN		30
#define IMAGE_FORMAT_LEN	10
#define	IO_STMT_LEN		8
#define ISSUE_CRIT_LEN          50
#define LAT_LEN			LAT_LON_LEN
#define LEVEL_LEN		20
#define LOC_DETAIL_LEN		10
#define LOC_ID_LEN		8
#define LOC_NAME_LEN		50
#define LOC_AREANAME_LEN	40
#define LOC_TYPE_LEN		20
#define LON_LEN			LAT_LON_LEN
#define LONG_ADDR_LEN		40
#define MISS_LEN                12
#define MODEL_LEN		20
#define MONTH_DAY_LEN            5
#define	MOSAIC_TYPE_LEN		10
#define NETWK_LEN		3
#define NUM_HOURLY_SLOTS        24
#define NUM_6HOURLY_SLOTS       4
#define NWR_FORMAT_LEN		5
#define NWR_AREA_LEN		25
#define NWR_TOWER_CODE_LEN	3
#define	OBS_ADDR_LEN		30
#define OBS_COMM_LEN		10
#define	OBS_FNAME_LEN		12
#define	OBS_LNAME_LEN		28
#define	OBS_PHONE_LEN		18
#define OBS_RECIP_LEN		15
#define OBS_SPONS_LEN		7
#define	OFFICE_LEN		20
#define	OFFNOTES_CLASS_LEN	8
#define OLD_DATUM_LEN		BOOL_LEN
#define OPER_QualityCode_LEN	8
#define OVERLAY_TYPE_LEN	20
#define OWNER_LEN		10
#define PARAM_LEN		20
#define PASSWORD_LEN		8
#define PERIOD_LEN		30
#define PHONE_LEN		12
#define PRECIP_SOURCE_LEN       8
#define PRESET_DESCR_LEN        30
#define PRESET_ID_LEN           8
#define PRESET_STRING_LEN       512
#define PROCESS_NAME_LEN	10
#define PROCESSOR_LEN           30
#define PROD_CATEG_LEN	        3
#define PRODUCT_LEN             10
#define PROXIMITY_LEN		6
#define PUB_LEN			20
#define PUB_LOC_LEN		25
#define QC_STATUS_LEN		7
#define RADAR_ID_LEN 		3
#define RADAR_ID_PREFIX_LEN 	1
#define	RADARLOC_NAME_LEN	20
#define RATE_AGNCY_LEN		20
#define RECTYPE_LEN             3
#define REFER_LEN		70
#define REMK_LEN		LONG_LEN
#define REPT_FREQ_LEN		4
#define REPT_TIME_LEN		8
#define REQ_PERIOD_LEN          30
#define	RES_MODEL_LEN		30
#define	RES_NAME_LEN		20
#define RES_REG_LEN		LONG_LEN
#define RES_USE_LEN		8
#define RFC_LEN			5
#define RFC_NAME_LEN		20
#define RFS_DESCR_LEN		20
#define RFS_RFC_LEN		8
#define RIV_BAS_LEN		30
#define S2_GRID_TYPE_LEN	2
#define SEASON_LEN		5
#define SERVICE_TYPE_LEN	20
#define SHEF_COMMENT_LEN	SHORT_LEN
#define SHEF_DUR_NAME_LEN       20
#define SHEF_DUR_CODE_LEN       CODE_LEN
#define SHEF_EX_LEN		CODE_LEN
#define SHEF_EX_NAME_LEN 	20
#define SHEF_PE_LEN		2
#define SHEF_PE_NAME_LEN 	20
#define SHEF_PE_TRANS_LEN       3
#define SHEF_PROB_LEN		1
#define SHEF_PROB_NAME_LEN	20
#define SHEF_QC_LEN		CODE_LEN
#define SHEF_QC_NAME_LEN	20
#define SHEF_SOURCE_LEN		CODE_LEN
#define SHEF_TS_LEN		2
#define SHEF_TS_NAME_LEN        20
#define SHEF_UNIT_LEN		8
#define SNOW_METH_LEN           30
#define SPONSOR_LEN		7
#define SRC_LEN			20
#define SSHP_MODEL_LEN          10
#define SSHP_PREFS_LEN          20
#define SSN_LEN			11
#define STATE_LEN		2
#define	STATE_NAME_LEN		20
#define STATION_NUM_LEN		10
#define STNTYPE_LEN 		4
#define STREAM_NAME_LEN		32
#define TASK_CODE_LEN		13
#define TELEM_PARAM_LEN		12
#define TELEM_PAY_LEN		10
#define TIDAL_EFF_LEN		8
#define TIME_LEN		5
#define TS_ID_LEN		8
#define TYPE_LEN		10
#define TZ_LEN			8
#define TZ_NAME_LEN		30
#define UGC_LEN			4
#define URL_LEN                 120
#define USCE_OFC_LEN		3
#define USGS_RATE_LEN           5
#define USERID_LEN		32
#define VERT_DATUM_LEN		20
#define VTEC_GEOID_LEN		24
#define VTEC_ACTION_LEN		3
#define VTEC_PHENOM_LEN		2
#define VTEC_PRODMODE_LEN	1
#define VTEC_SIGNIF_LEN		1
#define VTEC_CAUSE_LEN          2
#define VTEC_MODE_LEN		4
#define VTEC_RECORD_LEN         2
#define VTEC_SEVER_LEN          1
#define VTEC_NAME_LEN           25
#define WARN_OFC_LEN		3
#define WATSUP_CRIT_LEN         30
#define WATSUP_METH_LEN         50
#define WFO_LEN			3
#define WFO_NAME_LEN		32
#define WSFO_LEN		3
#define YES_NO_LEN		3
#define ZIP_LEN			10
#define ZONE_LEN                3
#define BIAS_LEN        21

#endif

