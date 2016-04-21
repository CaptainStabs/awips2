/*
** Generated by X-Designer
*/
/*
**LIBS: -lXm -lXt -lX11
*/

#include <stdlib.h>
#include <X11/Xatom.h>
#include <X11/Intrinsic.h>
#include <X11/Shell.h>

#include <Xm/Xm.h>
#include <Xm/ArrowB.h>
#include <Xm/DialogS.h>
#include <Xm/Form.h>
#include <Xm/Label.h>
#include <Xm/List.h>
#include <Xm/PushB.h>
#include <Xm/RowColumn.h>
#include <Xm/ScrollBar.h>
#include <Xm/Text.h>
#include <Xm/TextF.h>
#include <Xm/ToggleB.h>
#include <Xm/CascadeBG.h>
#include <Xm/LabelG.h>
#include <Xm/PushBG.h>


#include "preaccum.h"

Widget preaccumDS = (Widget) NULL;
Widget preaccumFO = (Widget) NULL;
Widget preaccum_showLB = (Widget) NULL;
Widget PCtslabelLB = (Widget) NULL;
Widget preaccum_PCtsSL = (Widget) NULL;
Widget preaccum_PCtsVSB = (Widget) NULL;
Widget preaccum_PCtsLI = (Widget) NULL;
Widget PPtslabelLB = (Widget) NULL;
Widget preaccum_PPtsSL = (Widget) NULL;
Widget preaccum_PPtsVSB = (Widget) NULL;
Widget preaccum_PPtsLI = (Widget) NULL;
Widget preaccum_locationTB = (Widget) NULL;
Widget preaccum_locationTX = (Widget) NULL;
Widget preaccum_sortOM = (Widget) NULL;
Widget preaccumsortLB = (Widget) NULL;
Widget preaccum_sortCB = (Widget) NULL;
Widget preaccum_sortPDM = (Widget) NULL;
Widget preaccum_lidPB = (Widget) NULL;
Widget preaccum_maxvalPB = (Widget) NULL;
Widget preaccum_optLB = (Widget) NULL;
Widget preaccum_accumTB = (Widget) NULL;
Widget preaccum_detailTB = (Widget) NULL;
Widget preaccum_endtimeLB = (Widget) NULL;
Widget preaccum_endTX = (Widget) NULL;
Widget preaccum_endHourUpAR = (Widget) NULL;
Widget preaccum_endHourDownAR = (Widget) NULL;
Widget preaccum_endDayUpAR = (Widget) NULL;
Widget preaccum_endDayDownAR = (Widget) NULL;
Widget preaccum_loaddataPB = (Widget) NULL;
Widget preaccumSTX = (Widget) NULL;
Widget preaccumHSB = (Widget) NULL;
Widget preaccumVSB = (Widget) NULL;
Widget preaccum_TL = (Widget) NULL;
Widget preaccum_closePB = (Widget) NULL;
Widget preaccum_printPB = (Widget) NULL;
Widget preaccum_savePB = (Widget) NULL;
Widget preaccum_hsaTB = (Widget) NULL;
Widget preaccum_hsaSL = (Widget) NULL;
Widget preaccum_hsaVSB = (Widget) NULL;
Widget preaccum_hsaLI = (Widget) NULL;
Widget preaccum_filterLB = (Widget) NULL;
Widget preaccum_sourceTB = (Widget) NULL;
Widget preaccum_otherTX = (Widget) NULL;
Widget preaccum_otherLB = (Widget) NULL;
Widget preaccum_durationSL = (Widget) NULL;
Widget preaccum_durationVSB = (Widget) NULL;
Widget preaccum_durationLI = (Widget) NULL;
Widget preaccum_durLB = (Widget) NULL;



void create_preaccumDS (Widget parent)
{
	Widget children[30];      /* Children to manage */
	Arg al[64];                    /* Arg List */
	register int ac = 0;           /* Arg Count */
	XmString *list_items[2];          /* For list items */
	XmString xmstrings[16];    /* temporary storage for XmStrings */

	XtSetArg(al[ac], XmNallowShellResize, TRUE); ac++;
	XtSetArg(al[ac], XmNtitle, "Point Precipitation Accumulations"); ac++;
	XtSetArg(al[ac], XmNminWidth, 910); ac++;
	XtSetArg(al[ac], XmNminHeight, 720); ac++;
	XtSetArg(al[ac], XmNmaxWidth, 910); ac++;
	XtSetArg(al[ac], XmNmaxHeight, 720); ac++;
	preaccumDS = XmCreateDialogShell ( parent, "preaccumDS", al, ac );
	ac = 0;
	XtSetArg(al[ac], XmNautoUnmanage, FALSE); ac++;
	preaccumFO = XmCreateForm ( preaccumDS, "preaccumFO", al, ac );
	ac = 0;
	xmstrings[0] = XmStringCreateLtoR ( "Select Time Period:", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_END); ac++;
	preaccum_showLB = XmCreateLabel ( preaccumFO, "preaccum_showLB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	xmstrings[0] = XmStringCreateLtoR ( "PC/Ctr", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_BEGINNING); ac++;
	PCtslabelLB = XmCreateLabel ( preaccumFO, "PCtslabelLB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	XtSetArg(al[ac], XmNselectionPolicy, XmMULTIPLE_SELECT); ac++;
	preaccum_PCtsLI = XmCreateScrolledList ( preaccumFO, "preaccum_PCtsLI", al, ac );
	ac = 0;
	preaccum_PCtsSL = XtParent ( preaccum_PCtsLI );

	XtSetArg(al[ac], XmNverticalScrollBar, &preaccum_PCtsVSB); ac++;
	XtGetValues(preaccum_PCtsSL, al, ac );
	ac = 0;
	XtSetArg(al[ac], XmNselectionPolicy, XmMULTIPLE_SELECT); ac++;
	XtSetValues ( preaccum_PCtsLI,al, ac );
	ac = 0;
	xmstrings[0] = XmStringCreateLtoR ( "PP/Inc", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_BEGINNING); ac++;
	PPtslabelLB = XmCreateLabel ( preaccumFO, "PPtslabelLB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	XtSetArg(al[ac], XmNselectionPolicy, XmMULTIPLE_SELECT); ac++;
	preaccum_PPtsLI = XmCreateScrolledList ( preaccumFO, "preaccum_PPtsLI", al, ac );
	ac = 0;
	preaccum_PPtsSL = XtParent ( preaccum_PPtsLI );

	XtSetArg(al[ac], XmNverticalScrollBar, &preaccum_PPtsVSB); ac++;
	XtGetValues(preaccum_PPtsSL, al, ac );
	ac = 0;
	XtSetArg(al[ac], XmNselectionPolicy, XmMULTIPLE_SELECT); ac++;
	XtSetValues ( preaccum_PPtsLI,al, ac );
	ac = 0;
	xmstrings[0] = XmStringCreateLtoR ( "By\nLocation:", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_BEGINNING); ac++;
	preaccum_locationTB = XmCreateToggleButton ( preaccumFO, "preaccum_locationTB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	XtSetArg(al[ac], XmNmaxLength, 8); ac++;
	preaccum_locationTX = XmCreateTextField ( preaccumFO, "preaccum_locationTX", al, ac );
	ac = 0;
	XmTextFieldSetString ( preaccum_locationTX, "" );
	XtSetArg(al[ac], XmNspacing, 5); ac++;
	xmstrings[0] = XmStringCreateLtoR("Sort:", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	preaccum_sortOM = XmCreateOptionMenu ( preaccumFO, "preaccum_sortOM", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	preaccumsortLB = XmOptionLabelGadget ( preaccum_sortOM );
	preaccum_sortCB = XmOptionButtonGadget ( preaccum_sortOM );
	XtSetArg(al[ac], XmNwidth, 22); ac++;
	XtSetArg(al[ac], XmNheight, 32); ac++;
	XtSetValues ( preaccumsortLB,al, ac );
	ac = 0;
	preaccum_sortPDM = XmCreatePulldownMenu ( preaccum_sortOM, "preaccum_sortPDM", al, ac );
	XtSetArg(al[ac], XmNwidth, 94); ac++;
	XtSetArg(al[ac], XmNheight, 25); ac++;
	xmstrings[0] = XmStringCreateLtoR ( "Location", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_CENTER); ac++;
	XtSetArg(al[ac], XmNrecomputeSize, FALSE); ac++;
	preaccum_lidPB = XmCreatePushButtonGadget ( preaccum_sortPDM, "preaccum_lidPB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	XtSetArg(al[ac], XmNwidth, 94); ac++;
	XtSetArg(al[ac], XmNheight, 25); ac++;
	xmstrings[0] = XmStringCreateLtoR ( "Value", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_CENTER); ac++;
	XtSetArg(al[ac], XmNrecomputeSize, FALSE); ac++;
	preaccum_maxvalPB = XmCreatePushButton ( preaccum_sortPDM, "preaccum_maxvalPB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	XtSetArg(al[ac], XmNx, 45); ac++;
	XtSetArg(al[ac], XmNy, 3); ac++;
	XtSetArg(al[ac], XmNwidth, 114); ac++;
	XtSetArg(al[ac], XmNheight, 33); ac++;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_CENTER); ac++;
	XtSetArg(al[ac], XmNrecomputeSize, TRUE); ac++;
	XtSetValues ( preaccum_sortCB,al, ac );
	ac = 0;
	xmstrings[0] = XmStringCreateLtoR ( "Options:", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_END); ac++;
	preaccum_optLB = XmCreateLabel ( preaccumFO, "preaccum_optLB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	xmstrings[0] = XmStringCreateLtoR ( "Add PP reports\nas needed", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_BEGINNING); ac++;
	XtSetArg(al[ac], XmNset, TRUE); ac++;
	preaccum_accumTB = XmCreateToggleButton ( preaccumFO, "preaccum_accumTB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	xmstrings[0] = XmStringCreateLtoR ( "Show Details", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_BEGINNING); ac++;
	preaccum_detailTB = XmCreateToggleButton ( preaccumFO, "preaccum_detailTB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	xmstrings[0] = XmStringCreateLtoR ( "Endtime:", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_END); ac++;
	preaccum_endtimeLB = XmCreateLabel ( preaccumFO, "preaccum_endtimeLB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	XtSetArg(al[ac], XmNmaxLength, 19); ac++;
	preaccum_endTX = XmCreateTextField ( preaccumFO, "preaccum_endTX", al, ac );
	ac = 0;
	XmTextFieldSetString ( preaccum_endTX, "" );
	preaccum_endHourUpAR = XmCreateArrowButton ( preaccumFO, "preaccum_endHourUpAR", al, ac );
	XtSetArg(al[ac], XmNarrowDirection, XmARROW_DOWN); ac++;
	preaccum_endHourDownAR = XmCreateArrowButton ( preaccumFO, "preaccum_endHourDownAR", al, ac );
	ac = 0;
	preaccum_endDayUpAR = XmCreateArrowButton ( preaccumFO, "preaccum_endDayUpAR", al, ac );
	XtSetArg(al[ac], XmNarrowDirection, XmARROW_DOWN); ac++;
	preaccum_endDayDownAR = XmCreateArrowButton ( preaccumFO, "preaccum_endDayDownAR", al, ac );
	ac = 0;
	xmstrings[0] = XmStringCreateLtoR ( "Load Data", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_CENTER); ac++;
	preaccum_loaddataPB = XmCreatePushButton ( preaccumFO, "preaccum_loaddataPB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	XtSetArg(al[ac], XmNeditable, FALSE); ac++;
	XtSetArg(al[ac], XmNeditMode, XmMULTI_LINE_EDIT); ac++;
	XtSetArg(al[ac], XmNscrollHorizontal, TRUE); ac++;
	preaccum_TL = XmCreateScrolledText ( preaccumFO, "preaccum_TL", al, ac );
	ac = 0;
	preaccumSTX = XtParent ( preaccum_TL );

	XtSetArg(al[ac], XmNhorizontalScrollBar, &preaccumHSB); ac++;
	XtSetArg(al[ac], XmNverticalScrollBar, &preaccumVSB); ac++;
	XtGetValues(preaccumSTX, al, ac );
	ac = 0;
	xmstrings[0] = XmStringCreateLtoR ( "Close", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	preaccum_closePB = XmCreatePushButton ( preaccumFO, "preaccum_closePB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	xmstrings[0] = XmStringCreateLtoR ( "Print", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	preaccum_printPB = XmCreatePushButton ( preaccumFO, "preaccum_printPB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	xmstrings[0] = XmStringCreateLtoR ( "Save", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	preaccum_savePB = XmCreatePushButtonGadget ( preaccumFO, "preaccum_savePB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	xmstrings[0] = XmStringCreateLtoR ( "By HSA:", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	preaccum_hsaTB = XmCreateToggleButton ( preaccumFO, "preaccum_hsaTB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	XtSetArg(al[ac], XmNselectionPolicy, XmMULTIPLE_SELECT); ac++;
	preaccum_hsaLI = XmCreateScrolledList ( preaccumFO, "preaccum_hsaLI", al, ac );
	ac = 0;
	preaccum_hsaSL = XtParent ( preaccum_hsaLI );

	XtSetArg(al[ac], XmNverticalScrollBar, &preaccum_hsaVSB); ac++;
	XtGetValues(preaccum_hsaSL, al, ac );
	ac = 0;
	XtSetArg(al[ac], XmNselectionPolicy, XmMULTIPLE_SELECT); ac++;
	XtSetValues ( preaccum_hsaLI,al, ac );
	ac = 0;
	xmstrings[0] = XmStringCreateLtoR ( "Filter:", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	preaccum_filterLB = XmCreateLabel ( preaccumFO, "preaccum_filterLB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	xmstrings[0] = XmStringCreateLtoR ( "By Data Sources:", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	preaccum_sourceTB = XmCreateToggleButton ( preaccumFO, "preaccum_sourceTB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	preaccum_otherTX = XmCreateTextField ( preaccumFO, "preaccum_otherTX", al, ac );
	xmstrings[0] = XmStringCreateLtoR ( "Other:", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	preaccum_otherLB = XmCreateLabel ( preaccumFO, "preaccum_otherLB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );
	XtSetArg(al[ac], XmNselectionPolicy, XmMULTIPLE_SELECT); ac++;
	XtSetArg(al[ac], XmNitemCount, 8); ac++;
	list_items [0] = (XmString *) XtMalloc ( sizeof (XmString) * 9 );
	list_items[0][0] = XmStringCreateLtoR("1 Hour", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	list_items[0][1] = XmStringCreateLtoR("3 Hour", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	list_items[0][2] = XmStringCreateLtoR("6 Hour", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	list_items[0][3] = XmStringCreateLtoR("12 Hour", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	list_items[0][4] = XmStringCreateLtoR("24 Hour", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	list_items[0][5] = XmStringCreateLtoR("48 Hour", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	list_items[0][6] = XmStringCreateLtoR("72 Hour", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	list_items[0][7] = XmStringCreateLtoR("Other", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	list_items[0][8] = NULL;
	XtSetArg(al[ac], XmNitems, list_items[0]); ac++;
	preaccum_durationLI = XmCreateScrolledList ( preaccumFO, "preaccum_durationLI", al, ac );
	ac = 0;
	while ( list_items[0][ac] )
		XmStringFree ( list_items[ 0 ][ac++] );
	ac = 0;
	XtFree ( (char *) list_items[0] );
	preaccum_durationSL = XtParent ( preaccum_durationLI );

	XtSetArg(al[ac], XmNverticalScrollBar, &preaccum_durationVSB); ac++;
	XtGetValues(preaccum_durationSL, al, ac );
	ac = 0;
	XtSetArg(al[ac], XmNselectionPolicy, XmMULTIPLE_SELECT); ac++;
	XtSetArg(al[ac], XmNitemCount, 8); ac++;
	list_items [0] = (XmString *) XtMalloc ( sizeof (XmString) * 9 );
	list_items[0][0] = XmStringCreateLtoR("1 Hour", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	list_items[0][1] = XmStringCreateLtoR("3 Hour", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	list_items[0][2] = XmStringCreateLtoR("6 Hour", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	list_items[0][3] = XmStringCreateLtoR("12 Hour", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	list_items[0][4] = XmStringCreateLtoR("24 Hour", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	list_items[0][5] = XmStringCreateLtoR("48 Hour", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	list_items[0][6] = XmStringCreateLtoR("72 Hour", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	list_items[0][7] = XmStringCreateLtoR("Other", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG);
	list_items[0][8] = NULL;
	XtSetArg(al[ac], XmNitems, list_items[0]); ac++;
	XtSetValues ( preaccum_durationLI,al, ac );
	ac = 0;
	while ( list_items[0][ac] )
		XmStringFree ( list_items[ 0 ][ac++] );
	ac = 0;
	XtFree ( (char *) list_items[0] );
	xmstrings[0] = XmStringCreateLtoR ( "Duration:", (XmStringCharSet)XmFONTLIST_DEFAULT_TAG );
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	preaccum_durLB = XmCreateLabel ( preaccumFO, "preaccum_durLB", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );


	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 4); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -28); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -144); ac++;
	XtSetValues ( preaccum_showLB,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 60); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -85); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 552); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -627); ac++;
	XtSetValues ( PCtslabelLB,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 88); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -184); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 556); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -616); ac++;
	XtSetValues ( preaccum_PCtsSL,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 60); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -85); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 636); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -701); ac++;
	XtSetValues ( PPtslabelLB,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 88); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -184); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 636); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -696); ac++;
	XtSetValues ( preaccum_PPtsSL,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 116); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -160); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 376); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -470); ac++;
	XtSetValues ( preaccum_locationTB,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 116); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -158); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 472); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -544); ac++;
	XtSetValues ( preaccum_locationTX,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 2); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -42); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 710); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -880); ac++;
	XtSetValues ( preaccum_sortOM,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 48); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -68); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 708); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -776); ac++;
	XtSetValues ( preaccum_optLB,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 112); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -156); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 708); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -844); ac++;
	XtSetValues ( preaccum_accumTB,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 76); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -106); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 708); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -843); ac++;
	XtSetValues ( preaccum_detailTB,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 36); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -59); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -67); ac++;
	XtSetValues ( preaccum_endtimeLB,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 36); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -71); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 96); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -326); ac++;
	XtSetValues ( preaccum_endTX,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 28); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -53); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 332); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -357); ac++;
	XtSetValues ( preaccum_endHourUpAR,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 52); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -77); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 332); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -357); ac++;
	XtSetValues ( preaccum_endHourDownAR,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 28); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -53); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 72); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -97); ac++;
	XtSetValues ( preaccum_endDayUpAR,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 52); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -77); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 72); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -97); ac++;
	XtSetValues ( preaccum_endDayDownAR,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 152); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -184); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 188); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -324); ac++;
	XtSetValues ( preaccum_loaddataPB,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 190); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -670); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 2); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -904); ac++;
	XtSetValues ( preaccumSTX,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 685); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -715); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 5); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -115); ac++;
	XtSetValues ( preaccum_closePB,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 685); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -715); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 780); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -905); ac++;
	XtSetValues ( preaccum_printPB,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 685); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -715); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 405); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -525); ac++;
	XtSetValues ( preaccum_savePB,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 28); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 376); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
	XtSetValues ( preaccum_hsaTB,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 24); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -112); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 464); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -544); ac++;
	XtSetValues ( preaccum_hsaSL,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 4); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 376); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
	XtSetValues ( preaccum_filterLB,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 28); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 552); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
	XtSetValues ( preaccum_sourceTB,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 98); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -134); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 250); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -354); ac++;
	XtSetValues ( preaccum_otherTX,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 108); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -132); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 172); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -248); ac++;
	XtSetValues ( preaccum_otherLB,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 80); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, -188); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 72); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_OPPOSITE_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, -166); ac++;
	XtSetValues ( preaccum_durationSL,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 84); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 2); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
	XtSetValues ( preaccum_durLB,al, ac );
	ac = 0;
	XtManageChild(preaccum_PCtsLI);
	XtManageChild(preaccum_PPtsLI);
	children[ac++] = preaccum_lidPB;
	children[ac++] = preaccum_maxvalPB;
	XtManageChildren(children, ac);
	ac = 0;
	XtSetArg(al[ac], XmNsubMenuId, preaccum_sortPDM); ac++;
	XtSetValues(preaccum_sortCB, al, ac );
	ac = 0;
	XtManageChild(preaccum_TL);
	XtManageChild(preaccum_hsaLI);
	XtManageChild(preaccum_durationLI);
	children[ac++] = preaccum_showLB;
	children[ac++] = PCtslabelLB;
	children[ac++] = PPtslabelLB;
	children[ac++] = preaccum_locationTB;
	children[ac++] = preaccum_locationTX;
	children[ac++] = preaccum_sortOM;
	children[ac++] = preaccum_optLB;
	children[ac++] = preaccum_accumTB;
	children[ac++] = preaccum_detailTB;
	children[ac++] = preaccum_endtimeLB;
	children[ac++] = preaccum_endTX;
	children[ac++] = preaccum_endHourUpAR;
	children[ac++] = preaccum_endHourDownAR;
	children[ac++] = preaccum_endDayUpAR;
	children[ac++] = preaccum_endDayDownAR;
	children[ac++] = preaccum_loaddataPB;
	children[ac++] = preaccum_closePB;
	children[ac++] = preaccum_printPB;
	children[ac++] = preaccum_savePB;
	children[ac++] = preaccum_hsaTB;
	children[ac++] = preaccum_filterLB;
	children[ac++] = preaccum_sourceTB;
	children[ac++] = preaccum_otherTX;
	children[ac++] = preaccum_otherLB;
	children[ac++] = preaccum_durLB;
	XtManageChildren(children, ac);
	ac = 0;
}

