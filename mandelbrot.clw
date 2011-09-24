; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMandelbrotView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mandelbrot.h"
LastPage=0

ClassCount=7
Class1=CMandelbrotApp
Class2=CMandelbrotDoc
Class3=CMandelbrotView
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MANDELTYPE
Class5=CChildFrame
Class6=CAboutDlg
Resource3=IDR_MAINFRAME
Class7=CMandelDlg
Resource4=IDD_AUSSCHNITT

[CLS:CMandelbrotApp]
Type=0
HeaderFile=mandelbrot.h
ImplementationFile=mandelbrot.cpp
Filter=N

[CLS:CMandelbrotDoc]
Type=0
HeaderFile=mandelbrotDoc.h
ImplementationFile=mandelbrotDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CMandelbrotDoc

[CLS:CMandelbrotView]
Type=0
HeaderFile=mandelbrotView.h
ImplementationFile=mandelbrotView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CMandelbrotView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=mandelbrot.cpp
ImplementationFile=mandelbrot.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_SCHWARZWEISS
Command10=ID_FARBIG
CommandCount=10

[MNU:IDR_MANDELTYPE]
Type=1
Class=CMandelbrotView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_AUSSCHNITT
Command16=ID_VIEW_TOOLBAR
Command17=ID_VIEW_STATUS_BAR
Command18=ID_WINDOW_NEW
Command19=ID_WINDOW_CASCADE
Command20=ID_WINDOW_TILE_HORZ
Command21=ID_WINDOW_ARRANGE
Command22=ID_APP_ABOUT
CommandCount=22

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_AUSSCHNITT]
Type=1
Class=CMandelDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_X1,edit,1350631552
Control9=IDC_X2,edit,1350631552
Control10=IDC_Y1,edit,1350631552
Control11=IDC_Y2,edit,1350631552
Control12=IDC_MAXITER,edit,1350631552

[CLS:CMandelDlg]
Type=0
HeaderFile=MandelDlg.h
ImplementationFile=MandelDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CMandelDlg
VirtualFilter=dWC

