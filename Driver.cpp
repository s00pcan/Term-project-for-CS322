#include <windows.h> // windows header file
#include "resource.h"
#include <vector>
#include <string>
#include "teacherType.h"
#include "database.h"
#include "auth.h"
#include <assert.h>

using namespace std;

database dbase;

void tests(){
	auth::removeUser("testUser","testPwd");
	auth::changePassword("chris","newPassword","password");

	assert(auth::login("chris","password"));
	assert(auth::login("chris","badpassword") == false);
	assert(auth::changePassword("chris","badpassword","newPassword") == false);
	assert(auth::changePassword("chris","password","newPassword"));
	assert(auth::changePassword("chris","newPassword","password"));
	assert(auth::addUser("testUser","testPwd"));
	assert(auth::login("testUser","testPwd"));
	assert(auth::removeUser("testUser","testPwd"));
}

#pragma region gui prototypes and globals
// enumerated constants for the child handles
enum {ID_buttonstu,ID_buttontch,ID_buttoncrs,ID_buttoncon,ID_buttonexit,ID_buttonreport,
//login
ID_userTXT,ID_passtxt,ID_loginaccept,ID_loginexit,
//main student main 
ID_STUTXT,ID_stuadd,ID_STUCHG,ID_STULKP,ID_STUDLT,ID_STUBACK,
//main teacher add screan
ID_stuid,ID_stufname,ID_stulname,ID_stuemail,ID_stuphone,
ID_stuidtxt,ID_stufnametxt,ID_stulnametxt,ID_stumnametxt,ID_stubdatetxt,ID_stuagetxt,
ID_stuclasstxt,ID_stusoctxt,ID_stupartxt,ID_stucls1txt,ID_stuclsg1txt,ID_stucls2txt,ID_stuclsg2txt,
ID_stucls3txt,ID_stuclsg3txt,ID_stucls4txt,ID_stuclsg4txt,ID_stucls5txt,ID_stuclsg5txt,ID_stuphonetxt,
ID_stuaccept,
//main teacher change screan
ID_stuidctxtc,ID_stufnamectxtc,ID_stulnamectxtc,ID_stumnamectxtc,ID_stubdatectxtc,ID_stuagectxtc,
ID_stuclassctxtc,ID_stusocctxtc,ID_stuparctxtc,ID_stucls1ctxtc,ID_stuclsg1ctxtc,ID_stucls2ctxtc,ID_stuclsg2ctxtc,
ID_stucls3ctxtc,ID_stuclsg3ctxtc,ID_stucls4ctxtc,ID_stuclsg4ctxtc,ID_stucls5ctxtc,ID_stuclsg5ctxtc,ID_stuphonetcxtc,
ID_stuacceptc,ID_reportexit,
//main student change screan
ID_stuidclbl,ID_stufnameclbl,ID_stulnameclbl,ID_stuemailclbl,ID_stuphoneclbl,ID_stuacceptl,

//main teacher screan
ID_tchTXT,ID_tchadd,ID_tchCHG,ID_tchLKP,ID_tchDLT,ID_tchBACK,
//main teacher add screan
ID_tchid,ID_tchfname,ID_tchlname,ID_tchemail,ID_tchphone,
ID_tchidtxt,ID_tchfnametxt,ID_tchlnametxt,ID_tchemailtxt,ID_tchphonetxt,ID_tchaccept,
//main teacher change screan
ID_tchidctxtc,ID_tchfnamectxtc,ID_tchlnamectxtc,ID_tchemailctxtc,ID_tchphonectxtc,ID_tchacceptc,
ID_tchfnametxtc,ID_tchlnametxtc,ID_tchemailtxtc,ID_tchphonetxtc,ID_tchidtxtc,
//main teacher change screan
ID_tchidclbl,ID_tchfnameclbl,ID_tchlnameclbl,ID_tchemailclbl,ID_tchphoneclbl,ID_tchacceptl,

//main course screan
ID_crsTXT,ID_crsadd,ID_crsCHG,ID_crsLKP,ID_crsDLT,ID_crsBACK,
//main course add screan
ID_crsid,ID_crsname,ID_crsdesc,ID_crsemail,ID_crsphone,
ID_crsidtxt,ID_crsnametxt,ID_crsdesctxt,ID_crsemailtxt,ID_crsphonetxt,ID_crsaccept,
//main course change screan
ID_crsidctxtc,ID_crsnamectxtc,ID_crsdescctxtc,ID_crsemailctxtc,ID_crsphonectxtc,ID_crsacceptc,
ID_crsnametxtc,ID_crsdesctxtc,ID_crsemailtxtc,ID_crsphonetxtc,ID_crsidtxtc,
//main course change screan
ID_crsidclbl,ID_crsnameclbl,ID_crsdescclbl,ID_crsemailclbl,ID_crsphoneclbl,ID_crsacceptl,

//main contact screan
ID_conTXT,ID_conadd,ID_conCHG,ID_conLKP,ID_conDLT,ID_conBACK,
//main contact add screan
ID_conid,ID_confname,ID_conlname,ID_conemail,ID_conphone,
ID_conidtxt,ID_confnametxt,ID_conlnametxt,ID_conemailtxt,ID_conphonetxt,ID_conaccept,ID_conaddresstxt,ID_conzziptxt,ID_constatetxt,
//main contact change screan
ID_conidctxtc,ID_confnamectxtc,ID_conlnamectxtc,ID_conemailctxtc,ID_conphonectxtc,ID_conacceptc,
ID_confnametxtc,ID_conlnametxtc,ID_conemailtxtc,ID_conphonetxtc,ID_conidtxtc,ID_conaddresstxtc,ID_conzziptxtc,ID_constatetxtc,
//main contact change screan
ID_conidclbl,ID_confnameclbl,ID_conlnameclbl,ID_conemailclbl,ID_conphoneclbl,ID_conacceptl,ID_conaddresslbl,ID_conzziplbl,ID_constatelbl
};

// function prototypes
LRESULT APIENTRY loginwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
LRESULT APIENTRY mainmenuwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
LRESULT APIENTRY reportwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);

//student screens
LRESULT APIENTRY studentmainwinProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
LRESULT APIENTRY studentaddwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
LRESULT APIENTRY studentchangewindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
LRESULT APIENTRY studentlookupwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);

//teacher screens
LRESULT APIENTRY teachermainwinProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
LRESULT APIENTRY teacheraddwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
LRESULT APIENTRY teacherchangewindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
LRESULT APIENTRY teacherlookupwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
//course screens
LRESULT APIENTRY coursemainwinProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
LRESULT APIENTRY courseaddwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
LRESULT APIENTRY coursechangewindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
LRESULT APIENTRY courselookupwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
//contact screens

LRESULT APIENTRY contactmainwinProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
LRESULT APIENTRY contactaddwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
LRESULT APIENTRY contactchangewindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
LRESULT APIENTRY contactlookupwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
//end new window

// Application Instance Handle
HINSTANCE g_hInst;

// window handles (unsigned long)'s
HWND mainmenuwin;
HWND loginwin;
HWND reportwin;
//student
HWND studentmainwin;
HWND studentaddwin;
HWND studentchangewin;
HWND studentlookupwin;
//teacher
HWND teachermainwin;
HWND teacheraddwin;
HWND teacherchangewin;
HWND teacherlookupwin;
 
//course
HWND coursemainwin;
HWND courseaddwin;
HWND coursechangewin;
HWND courselookupwin;
//contact
HWND contactmainwin;
HWND contactaddwin;
HWND contactchangewin;
HWND contactlookupwin;

HWND userlbl;
HWND passlbl;
HWND passchk;
HWND usertxt;
HWND passtxt;
HWND loginaccept; 
HWND loginexit; 

HWND static_label;
HWND static_image;
HWND edit;
HWND list;
HWND button;
HWND combo;
HWND buttonstu; 
HWND buttontch;
HWND buttoncrs;
HWND buttoncon;
HWND buttonexit;
HWND buttonreport;
//student menu
HWND stuadd;
HWND stuchange;
HWND stulookup;
HWND studelete;
HWND stuleave;
HWND stuback;
HWND stutxt;
//add student
HWND stuid;
HWND stufname;
HWND stumname;
HWND stulname;
HWND stubdate;
HWND stuage;
HWND stuclass;
HWND stusoc;
HWND stupar;
HWND stuclass1;
HWND stugrade1;
HWND stuclass2;
HWND stugrade2;
HWND stuclass3;
HWND stugrade3;
HWND stuclass4;
HWND stugrade4;
HWND stuclass5;
HWND stugrade5;



HWND stuidtxt;
HWND stufnametxt;
HWND stumnametxt;
HWND stulnametxt;
HWND stubdatetxt;
HWND stuagetxt;
HWND stuclasstxt;
HWND stusoctxt;
HWND stupartxt;
HWND stuclass1txt;
HWND stugrade1txt;
HWND stuclass2txt;
HWND stugrade2txt;
HWND stuclass3txt;
HWND stugrade3txt;
HWND stuclass4txt;
HWND stugrade4txt;
HWND stuclass5txt;
HWND stugrade5txt;

HWND stuaccept;
//change student
HWND stuidctxtc;
HWND stufnamectxtc;
HWND stumnamectxtc;
HWND stulnamectxtc;
HWND stubdatectxtc;
HWND stuagectxtc;
HWND stuclassctxtc;
HWND stusocctxtc;
HWND stuparctxtc;
HWND stuclass1ctxtc;
HWND stugrade1ctxtc;
HWND stuclass2ctxtc;
HWND stugrade2ctxtc;
HWND stuclass3ctxtc;
HWND stugrade3ctxtc;
HWND stuclass4ctxtc;
HWND stugrade4ctxtc;
HWND stuclass5ctxtc;
HWND stugrade5ctxtc;

HWND stuacceptc;

HWND stuidc;
HWND stufnamec;
HWND stumnamec;
HWND stulnamec;
HWND stubdatec;
HWND stuagec;
HWND stuclassc;
HWND stusocc;
HWND stuparc;
HWND stuclass1c;
HWND stugrade1c;
HWND stuclass2c;
HWND stugrade2c;
HWND stuclass3c;
HWND stugrade3c;
HWND stuclass4c;
HWND stugrade4c;
HWND stuclass5c;
HWND stugrade5c;
//lookup student
HWND stuidlbl;
HWND stufnamelbl;
HWND stumnamelbl;
HWND stulnamelbl;
HWND stubdatelbl;
HWND stuagelbl;
HWND stuclasslbl;
HWND stusoclbl;
HWND stuparlbl;
HWND stuclass1lbl;
HWND stugrade1lbl;
HWND stuclass2lbl;
HWND stugrade2lbl;
HWND stuclass3lbl;
HWND stugrade3lbl;
HWND stuclass4lbl;
HWND stugrade4lbl;
HWND stuclass5lbl;
HWND stugrade5lbl;
HWND stuacceptl;

//teacher main
HWND tchadd;
HWND tchchange;
HWND tchlookup;
HWND tchdelete;
HWND tchleave;
HWND tchback;
HWND tchtxt;

//teacher
HWND tchid;
HWND tchfname;
HWND tchlname;
HWND tchemail;
HWND tchphone;
HWND tchidtxt;
HWND tchfnametxt;
HWND tchlnametxt;
HWND tchemailtxt;
HWND tchphonetxt;
HWND tchaccept;
//change teacher
HWND tchidctxtc;
HWND tchfnamectxtc;
HWND tchlnamectxtc;
HWND tchemailctxtc;
HWND tchphonectxtc;
HWND tchacceptc;
HWND tchidc;
HWND tchfnamec;
HWND tchlnamec;
HWND tchemailc;
HWND tchphonec;
//lookup teacher
HWND tchidlbl;
HWND tchfnamelbl;
HWND tchlnamelbl;
HWND tchemaillbl;
HWND tchphonelbl;
HWND tchacceptl;

//course

HWND crsadd;
HWND crschange;
HWND crslookup;
HWND crsdelete;
HWND crsleave;
HWND crsback;
HWND crstxt;

HWND crsid;
HWND crsname;
HWND crsdesc;
HWND crsemail;
HWND crsphone;
HWND crsidtxt;
HWND crsnametxt;
HWND crsdesctxt;
HWND crsemailtxt;
HWND crsphonetxt;

HWND crsaccept;
//change course
HWND crsidctxtc;
HWND crsnamectxtc;
HWND crsdescctxtc;
HWND crsemailctxtc;
HWND crsphonectxtc;


HWND crsacceptc;
HWND crsidc;
HWND crsnamec;
HWND crsdescc;
HWND crsemailc;
HWND crsphonec;
//lookup course
HWND crsidlbl;
HWND crsnamelbl;
HWND crsdesclbl;
HWND crsemaillbl;
HWND crsphonelbl;
HWND crsacceptl;

//contact

HWND conadd;
HWND conchange;
HWND conlookup;
HWND condelete;
HWND conleave;
HWND conback;
HWND contxt;

HWND conid;
HWND confname;
HWND conlname;
HWND conemail;
HWND conphone;
HWND conaddress;
HWND constate;
HWND conzip;

HWND conidtxt;
HWND confnametxt;
HWND conlnametxt;
HWND conemailtxt;
HWND conphonetxt;
HWND conaddresstxt;
HWND constatetxt;
HWND conziptxt;
HWND conaccept;
//change contact
HWND conidctxtc;
HWND confnamectxtc;
HWND conlnamectxtc;
HWND conemailctxtc;
HWND conphonectxtc;
HWND conaddresstxtc;
HWND constatetxtc;
HWND conziptxtc;

HWND conacceptc;
HWND conidc;
HWND confnamec;
HWND conlnamec;
HWND conemailc;
HWND conphonec;
HWND conaddressc;
HWND constatec;
HWND conzipc;


//lookup contact
HWND conidlbl;
HWND confnamelbl;
HWND conlnamelbl;
HWND conemaillbl;
HWND conphonelbl;
HWND conaddresslbl;
HWND constatelbl;
HWND conziplbl;

HWND conacceptl;

HWND reportexit;
HWND reporth1lbl;
HWND reporth2lbl;
#pragma endregion

// using _stdcall the winmain entry
int APIENTRY WinMain(HINSTANCE hInst,HINSTANCE hPrev,LPSTR line,int CmdShow)
{
	g_hInst = hInst;
	MSG msg;
	WNDCLASS wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = CreateSolidBrush(RGB(245,245,245));
	wc.hInstance = hInst;
	wc.hIcon = LoadIcon(hInst,MAKEINTRESOURCE(IDI_ICON1));
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.lpfnWndProc = (WNDPROC) mainmenuwindowProc;
	wc.lpszClassName = "Mainmenu:)";
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wc);

	wc.lpszMenuName = NULL;
	wc.lpszClassName = "Login:)";
	wc.lpfnWndProc = (WNDPROC) loginwindowProc;

	RegisterClass(&wc);

	wc.lpszMenuName = NULL;
	wc.lpszClassName = "Report:)";
	wc.lpfnWndProc = (WNDPROC) reportwindowProc;

	RegisterClass(&wc);
//begin new window
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "StudentMain:)";
	wc.lpfnWndProc = (WNDPROC) studentmainwinProc;

	RegisterClass(&wc);
		wc.lpszMenuName = NULL;
	wc.lpszClassName = "StudentAdd:)";
	wc.lpfnWndProc = (WNDPROC) studentaddwindowProc;

	RegisterClass(&wc);
		wc.lpszMenuName = NULL;
	wc.lpszClassName = "StudentChange:)";
	wc.lpfnWndProc = (WNDPROC) studentchangewindowProc;

	RegisterClass(&wc);
		wc.lpszMenuName = NULL;
	wc.lpszClassName = "StudentLookup:)";
	wc.lpfnWndProc = (WNDPROC) studentlookupwindowProc;

//end new window
	RegisterClass(&wc);
	//begin teacher
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "TeacherMain:)";
	wc.lpfnWndProc = (WNDPROC) teachermainwinProc;

	RegisterClass(&wc);
		wc.lpszMenuName = NULL;
	wc.lpszClassName = "TeacherAdd:)";
	wc.lpfnWndProc = (WNDPROC) teacheraddwindowProc;

	RegisterClass(&wc);
		wc.lpszMenuName = NULL;
	wc.lpszClassName = "TeacherChange:)";
	wc.lpfnWndProc = (WNDPROC) teacherchangewindowProc;

	RegisterClass(&wc);
		wc.lpszMenuName = NULL;
	wc.lpszClassName = "TeacherLookup:)";
	wc.lpfnWndProc = (WNDPROC) teacherlookupwindowProc;
	RegisterClass(&wc);
	
	//begin course
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "CourseMain:)";
	wc.lpfnWndProc = (WNDPROC) coursemainwinProc;

	RegisterClass(&wc);
		wc.lpszMenuName = NULL;
	wc.lpszClassName = "CourseAdd:)";
	wc.lpfnWndProc = (WNDPROC) courseaddwindowProc;

	RegisterClass(&wc);
		wc.lpszMenuName = NULL;
	wc.lpszClassName = "CourseChange:)";
	wc.lpfnWndProc = (WNDPROC) coursechangewindowProc;

	RegisterClass(&wc);
		wc.lpszMenuName = NULL;
	wc.lpszClassName = "CourseLookup:)";
	wc.lpfnWndProc = (WNDPROC) courselookupwindowProc;

	RegisterClass(&wc);
	//begin Contact
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "ContactMain:)";
	wc.lpfnWndProc = (WNDPROC) contactmainwinProc;

	RegisterClass(&wc);
		wc.lpszMenuName = NULL;
	wc.lpszClassName = "ContactAdd:)";
	wc.lpfnWndProc = (WNDPROC) contactaddwindowProc;

	RegisterClass(&wc);
		wc.lpszMenuName = NULL;
	wc.lpszClassName = "ContactChange:)";
	wc.lpfnWndProc = (WNDPROC) contactchangewindowProc;

	RegisterClass(&wc);
		wc.lpszMenuName = NULL;
	wc.lpszClassName = "ContactLookup:)";
	wc.lpfnWndProc = (WNDPROC) contactlookupwindowProc;
	
	//end new window
	RegisterClass(&wc);
	
	// this is standard example two is ex :)
	
	//login screen
	reportwin = CreateWindow("Report:)","Report",WS_OVERLAPPEDWINDOW,800,400,500,300,0,0,hInst,0);
	loginwin = CreateWindow("Login:)","Login",WS_OVERLAPPEDWINDOW,800,400,300,200,0,0,hInst,0);
	mainmenuwin = CreateWindow("Mainmenu:)","Main Menu",WS_OVERLAPPEDWINDOW,800,400,200,275,0,0,hInst,0);
	
	//student screens
	studentmainwin = CreateWindow("StudentMain:)","Student Main", WS_OVERLAPPEDWINDOW,800,400,300,250,0,0,hInst,0);
	studentaddwin = CreateWindow("StudentAdd:)","Student Add", WS_OVERLAPPEDWINDOW,800,400,700,350,0,0,hInst,0);
	studentchangewin = CreateWindow("StudentChange:)","Student Change", WS_OVERLAPPEDWINDOW,800,400,700,350,0,0,hInst,0);
	studentlookupwin = CreateWindow("StudentLookup:)","Student Lookup", WS_OVERLAPPEDWINDOW,800,400,700,350,0,0,hInst,0);

	//teacher screens
	teachermainwin = CreateWindow("TeacherMain:)","Teacher Main", WS_OVERLAPPEDWINDOW,800,400,300,250,0,0,hInst,0);
	teacheraddwin = CreateWindow("TeacherAdd:)","Teacher Add", WS_OVERLAPPEDWINDOW,800,400,350,250,0,0,hInst,0);
	teacherchangewin = CreateWindow("TeacherChange:)","Teacher Change", WS_OVERLAPPEDWINDOW,800,400,350,250,0,0,hInst,0);
	teacherlookupwin = CreateWindow("TeacherLookup:)","Teacher Lookup", WS_OVERLAPPEDWINDOW,800,400,300,250,0,0,hInst,0);

	//course screens
	coursemainwin = CreateWindow("CourseMain:)","Course Main", WS_OVERLAPPEDWINDOW,800,400,300,250,0,0,hInst,0);
	courseaddwin = CreateWindow("CourseAdd:)","Course Add", WS_OVERLAPPEDWINDOW,800,400,350,250,0,0,hInst,0);
	coursechangewin = CreateWindow("CourseChange:)","Course Change", WS_OVERLAPPEDWINDOW,800,400,350,250,0,0,hInst,0);
	courselookupwin = CreateWindow("CourseLookup:)","Course Lookup", WS_OVERLAPPEDWINDOW,800,400,300,250,0,0,hInst,0);

	//contact screens
	contactmainwin = CreateWindow("ContactMain:)","Contact Main", WS_OVERLAPPEDWINDOW,800,400,300,250,0,0,hInst,0);
	contactaddwin = CreateWindow("ContactAdd:)","Contact Add", WS_OVERLAPPEDWINDOW,800,400,350,300,0,0,hInst,0);
	contactchangewin = CreateWindow("ContactChange:)","Contact Change", WS_OVERLAPPEDWINDOW,800,400,350,300,0,0,hInst,0);
	contactlookupwin = CreateWindow("ContactLookup:)","Contact Lookup", WS_OVERLAPPEDWINDOW,800,400,350,300,0,0,hInst,0);

	ShowWindow(loginwin,SW_SHOW);
	UpdateWindow(loginwin);
		
		while(GetMessage(&msg,0,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

// gui functions

#pragma region main window
LRESULT APIENTRY mainmenuwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	tests();

	switch(msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);// destroy code out of memory
		break;
	case WM_CREATE:// CREATING ALL THE CHILDREN OF THIS WINDOW
		{
			HWND stx;
			
			int id = 1;
			string fnm ="TestF";
			string lnm ="test L";
			string emailt ="test email" ;
			int phonet = 9894547841;
			teacherType	Teach;
			vector<teacherType> teacher;
			Teach.setTeacher(id,fnm,lnm,emailt,phonet);
			teacher.push_back(Teach);
			dbase.setteachervec(teacher,dbase);
			
			buttonstu = CreateWindow("Button","Maintain Students",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,25,140,30,hwnd,(HMENU)ID_buttonstu,g_hInst,0);
			buttontch = CreateWindow("Button","Maintain Teachers",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,60,140,30,hwnd,(HMENU)ID_buttontch,g_hInst,0);	
			buttoncrs = CreateWindow("Button","Maintain Course",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,95,140,30,hwnd,(HMENU)ID_buttoncrs,g_hInst,0);	
			buttoncon = CreateWindow("Button","Maintain Contacts",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,130,140,30,hwnd,(HMENU)ID_buttoncon,g_hInst,0);	
			buttonreport = CreateWindow("Button","Run Reports",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,165,140,30,hwnd,(HMENU)ID_buttonreport,g_hInst,0);	
			buttonexit = CreateWindow("Button","Logout/exit program",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,200,140,30,hwnd,(HMENU)ID_buttonexit,g_hInst,0);	
			
			/*stx = CreateWindow("Static","A Random Static Label",WS_CHILD | WS_VISIBLE ,0,0,200,25,hwnd,0,g_hInst,0);
			static_label = CreateWindow("Static","This static label",WS_CHILD | WS_VISIBLE,205,0,200,25,hwnd,0,g_hInst,0);
			edit = CreateWindow("Edit","A Windows Edit Box",WS_BORDER | WS_VSCROLL | WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL,5,35,200,200,hwnd,(HMENU)ID_EDIT,g_hInst,0);
			list = CreateWindow("ListBox",NULL, LBS_NOTIFY | WS_CHILD | WS_VISIBLE | WS_VSCROLL|WS_BORDER,5,250,200,200,hwnd,(HMENU)ID_LIST,g_hInst,0);
			button = CreateWindow("Button","About",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,350,5,100,25,hwnd,(HMENU)ID_BUTTON,g_hInst,0);
			static_image = CreateWindow("Static",NULL,WS_CHILD | WS_VISIBLE | SS_BITMAP,350,40,0,0,hwnd,(HMENU)ID_IMAGE,g_hInst,0);
			SendMessage(static_image,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)(HBITMAP)LoadBitmap(g_hInst,MAKEINTRESOURCE(IDB_BITMAP1)));
			combo = CreateWindow("ComboBox",NULL,WS_BORDER | CBS_DISABLENOSCROLL | WS_CHILD | CBS_DROPDOWNLIST | WS_VISIBLE,350,400,200,200,hwnd,(HMENU)ID_COMBO,g_hInst,0);
			SendMessage(combo,CB_ADDSTRING,255,(LPARAM)(LPCSTR)"addstuff");*/
		}
		break;
	case WM_COMMAND:
		{
			// child notification messages
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				switch(LOWORD(wParam))
				{
				case ID_buttonstu:
					{
						// code
					
						ShowWindow(studentmainwin,SW_SHOW);
						//hides the window
						ShowWindow(mainmenuwin,SW_HIDE);
					}
					break;
						case ID_buttontch:
					{
						// code
						ShowWindow(teachermainwin,SW_SHOW);
						//hides the window
						ShowWindow(mainmenuwin,SW_HIDE);
					
						//hides the window
						//ShowWindow(studentmainwin,SW_HIDE);
					}
					break;
						case ID_buttoncrs:
					{
						// code
							ShowWindow(mainmenuwin,SW_HIDE);
						////hides the window
						ShowWindow(coursemainwin,SW_SHOW);
						//hides the window
						//ShowWindow(studentmainwin,SW_HIDE);


						//	//used to get the text from an object
						// TCHAR szBuf[80];
						//GetWindowText(button0,szBuf,80);
						//strData= szBuf;
						////end get txt from an object
						//vector<string> tester;
						//tester.push_back("My name is tommy");
						////used to set txt to an object
						//string strData;
						//strData = tester[0];
						//SetWindowText(label1,strData.c_str());
						////end setting object txt
						//strData = "My data";
						//SetWindowText(button0,strData.c_str());
						//break;
					}
					break;
						case ID_buttoncon:
					{
					
						ShowWindow(mainmenuwin,SW_HIDE);
						////hides the window
						ShowWindow(contactmainwin,SW_SHOW);
					}
					break;
						case ID_buttonreport:
					{
						// code
						ShowWindow(reportwin,SW_SHOW);
						//hides the window
						ShowWindow(mainmenuwin,SW_HIDE);
					
						//hides the window
						//ShowWindow(studentmainwin,SW_HIDE);
					}
					break;
						case ID_buttonexit:
					{
						SendMessage(mainmenuwin,WM_CLOSE,0,0);
					}
					break;

				}
				break;
		}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}
#pragma endregion

#pragma region other windows
LRESULT APIENTRY reportwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
vector<teacherType> teach;
dbase.getteachervec(teach,dbase);
	switch(msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);// destroy code out of memory
		break;
	case WM_CREATE:// CREATING ALL THE CHILDREN OF THIS WINDOW
		{
			
			HWND stx;
			reporth1lbl = CreateWindow("Static","Report",WS_CHILD | WS_VISIBLE,25,25,75,25,hwnd,0,g_hInst,0);	
			reporth2lbl = CreateWindow("Static","Sort",WS_CHILD | WS_VISIBLE,200,25,75,25,hwnd,0,g_hInst,0);	
			
			reportexit = CreateWindow("Button","Accept",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,300,200,140,30,hwnd,(HMENU)ID_reportexit,g_hInst,0);
		
			/*stx = CreateWindow("Static","A Random Static Label",WS_CHILD | WS_VISIBLE ,0,0,200,25,hwnd,0,g_hInst,0);
			static_label = CreateWindow("Static","This static label",WS_CHILD | WS_VISIBLE,205,0,200,25,hwnd,0,g_hInst,0);
			edit = CreateWindow("Edit","A Windows Edit Box",WS_BORDER | WS_VSCROLL | WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL,5,35,200,200,hwnd,(HMENU)ID_EDIT,g_hInst,0);
			list = CreateWindow("ListBox",NULL, LBS_NOTIFY | WS_CHILD | WS_VISIBLE | WS_VSCROLL|WS_BORDER,5,250,200,200,hwnd,(HMENU)ID_LIST,g_hInst,0);
			button = CreateWindow("Button","About",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,350,5,100,25,hwnd,(HMENU)ID_BUTTON,g_hInst,0);
			static_image = CreateWindow("Static",NULL,WS_CHILD | WS_VISIBLE | SS_BITMAP,350,40,0,0,hwnd,(HMENU)ID_IMAGE,g_hInst,0);
			SendMessage(static_image,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)(HBITMAP)LoadBitmap(g_hInst,MAKEINTRESOURCE(IDB_BITMAP1)));
			combo = CreateWindow("ComboBox",NULL,WS_BORDER | CBS_DISABLENOSCROLL | WS_CHILD | CBS_DROPDOWNLIST | WS_VISIBLE,350,400,200,200,hwnd,(HMENU)ID_COMBO,g_hInst,0);
			SendMessage(combo,CB_ADDSTRING,255,(LPARAM)(LPCSTR)"addstuff");*/
		}
		break;
	case WM_COMMAND:
		{

			// child notification messages
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				switch(LOWORD(wParam))
				{
				case ID_reportexit:
					{
						// code
					

						ShowWindow(mainmenuwin,SW_SHOW);
						//hides the window
						ShowWindow(reportwin,SW_HIDE);
					}
					break;
					
				}
				break;

				
			
		}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}

// on the menu command
LRESULT APIENTRY loginwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{

	switch(msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);// destroy code out of memory
		break;
	case WM_CREATE:// CREATING ALL THE CHILDREN OF THIS WINDOW
		{
			HWND stx;
		
			usertxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,100,25,150,20,hwnd,(HMENU)ID_userTXT,g_hInst,0);
			passtxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,100,50,150,20,hwnd,(HMENU)ID_passtxt,g_hInst,0);
			
			
			userlbl = CreateWindow("Static","User ID:",WS_CHILD | WS_VISIBLE,25,25,75,25,hwnd,0,g_hInst,0);	
			passlbl = CreateWindow("Static","Password:",WS_CHILD | WS_VISIBLE,25,50,75,25,hwnd,0,g_hInst,0);	
			
			loginaccept = CreateWindow("Button","Login",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,75,100,30,hwnd,(HMENU)ID_loginaccept,g_hInst,0);
			loginexit = CreateWindow("Button","Exit",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,150,75,100,30,hwnd,(HMENU)ID_loginexit,g_hInst,0);
		
			/*stx = CreateWindow("Static","A Random Static Label",WS_CHILD | WS_VISIBLE ,0,0,200,25,hwnd,0,g_hInst,0);
			static_label = CreateWindow("Static","This static label",WS_CHILD | WS_VISIBLE,205,0,200,25,hwnd,0,g_hInst,0);
			edit = CreateWindow("Edit","A Windows Edit Box",WS_BORDER | WS_VSCROLL | WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL,5,35,200,200,hwnd,(HMENU)ID_EDIT,g_hInst,0);
			list = CreateWindow("ListBox",NULL, LBS_NOTIFY | WS_CHILD | WS_VISIBLE | WS_VSCROLL|WS_BORDER,5,250,200,200,hwnd,(HMENU)ID_LIST,g_hInst,0);
			button = CreateWindow("Button","About",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,350,5,100,25,hwnd,(HMENU)ID_BUTTON,g_hInst,0);
			static_image = CreateWindow("Static",NULL,WS_CHILD | WS_VISIBLE | SS_BITMAP,350,40,0,0,hwnd,(HMENU)ID_IMAGE,g_hInst,0);
			SendMessage(static_image,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)(HBITMAP)LoadBitmap(g_hInst,MAKEINTRESOURCE(IDB_BITMAP1)));
			combo = CreateWindow("ComboBox",NULL,WS_BORDER | CBS_DISABLENOSCROLL | WS_CHILD | CBS_DROPDOWNLIST | WS_VISIBLE,350,400,200,200,hwnd,(HMENU)ID_COMBO,g_hInst,0);
			SendMessage(combo,CB_ADDSTRING,255,(LPARAM)(LPCSTR)"addstuff");*/
		}
		break;
	case WM_COMMAND:
		{

			// child notification messages
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				switch(LOWORD(wParam))
				{
				case ID_loginaccept:
					{
						// code
					
						ShowWindow(loginwin,SW_HIDE);
						//hides the window
						ShowWindow(mainmenuwin,SW_SHOW);
					}
					break;
						case ID_loginexit:
					{
						// code
					
						SendMessage(loginwin,WM_CLOSE,0,0);
					}
					break;

				}
				break;

				
			
		}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}

// about window process
LRESULT APIENTRY studentmainwinProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{

	switch(msg)
	{
	case WM_CLOSE:
		ShowWindow(hwnd,SW_HIDE);
		break;
	case WM_CREATE:
		{

			stuadd = CreateWindow("Button","Add",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,25,55,30,hwnd,(HMENU)ID_stuadd,g_hInst,0);
			stuchange = CreateWindow("Button","Change",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,60,55,30,hwnd,(HMENU)ID_STUCHG,g_hInst,0);
			studelete = CreateWindow("Button","Delete",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,95,55,30,hwnd,(HMENU)ID_STUDLT,g_hInst,0);
			stulookup = CreateWindow("Button","Lookup",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,130,55,30,hwnd,(HMENU)ID_STULKP,g_hInst,0);
			stuback = CreateWindow("Button","Back",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,165,55,30,hwnd,(HMENU)ID_STUBACK,g_hInst,0);
			stutxt = CreateWindow("Edit","",WS_BORDER | WS_CHILD | WS_VISIBLE ,100,28,150,20,hwnd,(HMENU)ID_STUTXT,g_hInst,0);
			
			
			/*		HWND buttonx;
			buttonx = CreateWindow("Button","Ok!",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,200-55,200,100,25,hwnd,(HMENU)ID_BUTTON2,g_hInst,0);
			HWND stx;
			stx = CreateWindow("Static","Example for my friends, you can do what you need with this. :)",WS_CHILD|WS_VISIBLE,5,5,200,150,hwnd,0,g_hInst,0);*/

		}
	    	break;
	case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				{
					switch(LOWORD(wParam))
					{
					case ID_stuadd:
						{
							ShowWindow(studentmainwin,SW_HIDE);
						////hides the window
						ShowWindow(studentaddwin,SW_SHOW);
						}
						break;
						case ID_STUCHG:
						{
							ShowWindow(studentmainwin,SW_HIDE);
						////hides the window
						ShowWindow(studentchangewin,SW_SHOW);
						}
						break;
						case ID_STUDLT:
						{
							//delete from hash and index
							MessageBox(0,"Record was deleted","Mainmenu",MB_OK|MB_ICONINFORMATION);
							break;
						}
						break;
						case ID_STULKP:
						{
							ShowWindow(studentmainwin,SW_HIDE);
						////hides the window
						ShowWindow(studentlookupwin,SW_SHOW);
						}
						break;
						case ID_STUBACK:
						{
						ShowWindow(studentmainwin,SW_HIDE);
						////hides the window
						ShowWindow(mainmenuwin,SW_SHOW);
						//saves the database
						}
						break;
					}
				}
				break;
			}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}
LRESULT APIENTRY studentaddwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	
	switch(msg)
	{
	case WM_CLOSE:
		ShowWindow(hwnd,SW_HIDE);
		break;
	case WM_CREATE:
		{
			stuidtxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,25,175,20,hwnd,(HMENU)ID_stuidtxt,g_hInst,0);
			stufnametxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,50,175,20,hwnd,(HMENU)ID_stufnametxt,g_hInst,0);
			stumnametxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,75,175,20,hwnd,(HMENU)ID_stumnametxt,g_hInst,0);
			stulnametxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,100,175,20,hwnd,(HMENU)ID_stulnametxt,g_hInst,0);
			stubdatetxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,125,175,20,hwnd,(HMENU)ID_stubdatetxt,g_hInst,0);
			stuagetxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,150,175,20,hwnd,(HMENU)ID_stuagetxt,g_hInst,0);
			stuclasstxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,175,175,20,hwnd,(HMENU)ID_stuclasstxt,g_hInst,0);
			stusoctxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,200,175,20,hwnd,(HMENU)ID_stusoctxt,g_hInst,0);
			stupartxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,225,175,20,hwnd,(HMENU)ID_stupartxt,g_hInst,0);

			stuclass1txt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,25,175,20,hwnd,(HMENU)ID_stucls1txt,g_hInst,0);
			stugrade1txt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,50,175,20,hwnd,(HMENU)ID_stuclsg1txt,g_hInst,0);
			stuclass2txt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,75,175,20,hwnd,(HMENU)ID_stucls2txt,g_hInst,0);
			stugrade2txt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,100,175,20,hwnd,(HMENU)ID_stuclsg2txt,g_hInst,0);
			stuclass3txt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,125,175,20,hwnd,(HMENU)ID_stucls3txt,g_hInst,0);
			stugrade3txt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,150,175,20,hwnd,(HMENU)ID_stuclsg3txt,g_hInst,0);
			stuclass4txt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,175,175,20,hwnd,(HMENU)ID_stucls4txt,g_hInst,0);
			stugrade4txt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,200,175,20,hwnd,(HMENU)ID_stuclsg4txt,g_hInst,0);
			stuclass5txt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,225,175,20,hwnd,(HMENU)ID_stucls5txt,g_hInst,0);
			stugrade5txt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,250,175,20,hwnd,(HMENU)ID_stuclsg5txt,g_hInst,0);
			
			stuaccept = CreateWindow("Button","Accept",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,250,55,30,hwnd,(HMENU)ID_stuaccept,g_hInst,0);
			
			stuid = CreateWindow("Static","Student Id:",WS_CHILD | WS_VISIBLE,25,25,100,25,hwnd,0,g_hInst,0);	
			stufname = CreateWindow("Static","First Name:",WS_CHILD | WS_VISIBLE,25,50,100,25,hwnd,0,g_hInst,0);	
			stumname = CreateWindow("Static","Middle Name:",WS_CHILD | WS_VISIBLE,25,75,100,25,hwnd,0,g_hInst,0);	
			stulname = CreateWindow("Static","Last Name:",WS_CHILD | WS_VISIBLE,25,100,100,25,hwnd,0,g_hInst,0);	
			stubdate = CreateWindow("Static","Birthdate:",WS_CHILD | WS_VISIBLE,25,124,100,25,hwnd,0,g_hInst,0);	
			stuage = CreateWindow("Static","Age:",WS_CHILD | WS_VISIBLE,25,150,100,25,hwnd,0,g_hInst,0);	
			stuclass = CreateWindow("Static","Class:",WS_CHILD | WS_VISIBLE,25,175,100,25,hwnd,0,g_hInst,0);	
			stusoc = CreateWindow("Static","Social Sec #:",WS_CHILD | WS_VISIBLE,25,200,100,25,hwnd,0,g_hInst,0);	
			stupar = CreateWindow("Static","Parent Id:",WS_CHILD | WS_VISIBLE,25,225,100,25,hwnd,0,g_hInst,0);	

			stuclass1 = CreateWindow("Static","Class 1:",WS_CHILD | WS_VISIBLE,350,25,100,25,hwnd,0,g_hInst,0);	
			stugrade1 = CreateWindow("Static","Class 1 grade:",WS_CHILD | WS_VISIBLE,350,50,100,25,hwnd,0,g_hInst,0);	
			stuclass2 = CreateWindow("Static","Class 2:",WS_CHILD | WS_VISIBLE,350,75,100,25,hwnd,0,g_hInst,0);	
			stugrade2 = CreateWindow("Static","Class 2 grade:",WS_CHILD | WS_VISIBLE,350,100,100,25,hwnd,0,g_hInst,0);		
			stuclass3 = CreateWindow("Static","Class 3:",WS_CHILD | WS_VISIBLE,350,125,100,25,hwnd,0,g_hInst,0);	
			stugrade3 = CreateWindow("Static","Class 3 grade:",WS_CHILD | WS_VISIBLE,350,150,100,25,hwnd,0,g_hInst,0);	
			stuclass4 = CreateWindow("Static","Class 4:",WS_CHILD | WS_VISIBLE,350,175,100,25,hwnd,0,g_hInst,0);	
			stugrade4 = CreateWindow("Static","Class 4 grade:",WS_CHILD | WS_VISIBLE,350,200,100,25,hwnd,0,g_hInst,0);	
			stuclass5 = CreateWindow("Static","Class 5:",WS_CHILD | WS_VISIBLE,350,225,100,25,hwnd,0,g_hInst,0);	
			stugrade5 = CreateWindow("Static","Class 5 grade:",WS_CHILD | WS_VISIBLE,350,250,100,25,hwnd,0,g_hInst,0);	



			/*		HWND buttonx;
			buttonx = CreateWindow("Button","Ok!",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,200-55,200,100,25,hwnd,(HMENU)ID_BUTTON2,g_hInst,0);
			HWND stx;
			stx = CreateWindow("Static","Example for my friends, you can do what you need with this. :)",WS_CHILD|WS_VISIBLE,5,5,200,150,hwnd,0,g_hInst,0);*/

		}
	    	break;
	case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				{
					switch(LOWORD(wParam))
					{
					case ID_stuaccept:
						{
							ShowWindow(studentaddwin,SW_HIDE);
						//hides the window
						ShowWindow(studentmainwin,SW_SHOW);
						//saves the database
						}
						break;
					}
				}
				break;
			}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}

LRESULT APIENTRY studentchangewindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	
		switch(msg)
	{
	case WM_CLOSE:
		ShowWindow(hwnd,SW_HIDE);
		break;
	case WM_CREATE:
		{

			stuidctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,25,175,20,hwnd,(HMENU)ID_stuidctxtc,g_hInst,0);
			stufnamectxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,50,175,20,hwnd,(HMENU)ID_stufnamectxtc,g_hInst,0);
			stumnamectxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,75,175,20,hwnd,(HMENU)ID_stumnamectxtc,g_hInst,0);
			stulnamectxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,100,175,20,hwnd,(HMENU)ID_stulnamectxtc,g_hInst,0);
			stubdatectxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,125,175,20,hwnd,(HMENU)ID_stubdatectxtc,g_hInst,0);
			stuagectxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,150,175,20,hwnd,(HMENU)ID_stuagectxtc,g_hInst,0);
			stuclassctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,175,175,20,hwnd,(HMENU)ID_stuclassctxtc,g_hInst,0);
			stusocctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,200,175,20,hwnd,(HMENU)ID_stusocctxtc,g_hInst,0);
			stuparctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,225,175,20,hwnd,(HMENU)ID_stuparctxtc,g_hInst,0);

			stuclass1ctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,25,175,20,hwnd,(HMENU)ID_stucls1ctxtc,g_hInst,0);
			stugrade1ctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,50,175,20,hwnd,(HMENU)ID_stuclsg1ctxtc,g_hInst,0);
			stuclass2ctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,75,175,20,hwnd,(HMENU)ID_stucls2ctxtc,g_hInst,0);
			stugrade2ctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,100,175,20,hwnd,(HMENU)ID_stuclsg2ctxtc,g_hInst,0);
			stuclass3ctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,125,175,20,hwnd,(HMENU)ID_stucls3ctxtc,g_hInst,0);
			stugrade3ctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,150,175,20,hwnd,(HMENU)ID_stuclsg3ctxtc,g_hInst,0);
			stuclass4ctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,175,175,20,hwnd,(HMENU)ID_stucls4ctxtc,g_hInst,0);
			stugrade4ctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,200,175,20,hwnd,(HMENU)ID_stuclsg4ctxtc,g_hInst,0);
			stuclass5ctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,225,175,20,hwnd,(HMENU)ID_stucls5ctxtc,g_hInst,0);
			stugrade5ctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,450,250,175,20,hwnd,(HMENU)ID_stuclsg5ctxtc,g_hInst,0);
			
			stuacceptc = CreateWindow("Button","Accept",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,250,55,30,hwnd,(HMENU)ID_stuacceptc,g_hInst,0);
			
			stuidc = CreateWindow("Static","Student Id:",WS_CHILD | WS_VISIBLE,25,25,100,25,hwnd,0,g_hInst,0);	
			stufnamec = CreateWindow("Static","First Name:",WS_CHILD | WS_VISIBLE,25,50,100,25,hwnd,0,g_hInst,0);	
			stumnamec = CreateWindow("Static","Middle Name:",WS_CHILD | WS_VISIBLE,25,75,100,25,hwnd,0,g_hInst,0);	
			stulnamec = CreateWindow("Static","Last Name:",WS_CHILD | WS_VISIBLE,25,100,100,25,hwnd,0,g_hInst,0);	
			stubdatec = CreateWindow("Static","Birthdate:",WS_CHILD | WS_VISIBLE,25,124,100,25,hwnd,0,g_hInst,0);	
			stuagec = CreateWindow("Static","Age:",WS_CHILD | WS_VISIBLE,25,150,100,25,hwnd,0,g_hInst,0);	
			stuclassc = CreateWindow("Static","Class:",WS_CHILD | WS_VISIBLE,25,175,100,25,hwnd,0,g_hInst,0);	
			stusocc = CreateWindow("Static","Social Sec #:",WS_CHILD | WS_VISIBLE,25,200,100,25,hwnd,0,g_hInst,0);	
			stuparc = CreateWindow("Static","Parent Id:",WS_CHILD | WS_VISIBLE,25,225,100,25,hwnd,0,g_hInst,0);	

			stuclass1c = CreateWindow("Static","Class 1:",WS_CHILD | WS_VISIBLE,350,25,100,25,hwnd,0,g_hInst,0);	
			stugrade1c = CreateWindow("Static","Class 1 grade:",WS_CHILD | WS_VISIBLE,350,50,100,25,hwnd,0,g_hInst,0);	
			stuclass2c = CreateWindow("Static","Class 2:",WS_CHILD | WS_VISIBLE,350,75,100,25,hwnd,0,g_hInst,0);	
			stugrade2c = CreateWindow("Static","Class 2 grade:",WS_CHILD | WS_VISIBLE,350,100,100,25,hwnd,0,g_hInst,0);		
			stuclass3c = CreateWindow("Static","Class 3:",WS_CHILD | WS_VISIBLE,350,125,100,25,hwnd,0,g_hInst,0);	
			stugrade3c = CreateWindow("Static","Class 3 grade:",WS_CHILD | WS_VISIBLE,350,150,100,25,hwnd,0,g_hInst,0);	
			stuclass4c = CreateWindow("Static","Class 4:",WS_CHILD | WS_VISIBLE,350,175,100,25,hwnd,0,g_hInst,0);	
			stugrade4c = CreateWindow("Static","Class 4 grade:",WS_CHILD | WS_VISIBLE,350,200,100,25,hwnd,0,g_hInst,0);	
			stuclass5c = CreateWindow("Static","Class 5:",WS_CHILD | WS_VISIBLE,350,225,100,25,hwnd,0,g_hInst,0);	
			stugrade5c = CreateWindow("Static","Class 5 grade:",WS_CHILD | WS_VISIBLE,350,250,100,25,hwnd,0,g_hInst,0);		
			//SetWindowText(edit,"3");
			
			/*		HWND buttonx;
			buttonx = CreateWindow("Button","Ok!",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,200-55,200,100,25,hwnd,(HMENU)ID_BUTTON2,g_hInst,0);
			HWND stx;
			stx = CreateWindow("Static","Example for my friends, you can do what you need with this. :)",WS_CHILD|WS_VISIBLE,5,5,200,150,hwnd,0,g_hInst,0);*/

		}
	    	break;
	case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				{
					switch(LOWORD(wParam))
					{
					case ID_stuacceptc:
						{
							ShowWindow(studentchangewin,SW_HIDE);
						//hides the window
						ShowWindow(studentmainwin,SW_SHOW);
						//saves the database
						}
						break;
					}
				}
				break;
			}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}
LRESULT APIENTRY studentlookupwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	
	switch(msg)
	{
	case WM_CLOSE:
		ShowWindow(hwnd,SW_HIDE);
		break;
	case WM_CREATE:
		{


			stuidlbl = CreateWindow("Static","Student Id:",WS_CHILD | WS_VISIBLE,25,25,100,25,hwnd,0,g_hInst,0);	
			stufnamelbl = CreateWindow("Static","First Name:",WS_CHILD | WS_VISIBLE,25,50,100,25,hwnd,0,g_hInst,0);	
			stumnamelbl = CreateWindow("Static","Middle Name:",WS_CHILD | WS_VISIBLE,25,75,100,25,hwnd,0,g_hInst,0);	
			stulnamelbl = CreateWindow("Static","Last Name:",WS_CHILD | WS_VISIBLE,25,100,100,25,hwnd,0,g_hInst,0);	
			stubdatelbl = CreateWindow("Static","Birthdate:",WS_CHILD | WS_VISIBLE,25,124,100,25,hwnd,0,g_hInst,0);	
			stuagelbl = CreateWindow("Static","Age:",WS_CHILD | WS_VISIBLE,25,150,100,25,hwnd,0,g_hInst,0);	
			stuclasslbl = CreateWindow("Static","Class:",WS_CHILD | WS_VISIBLE,25,175,100,25,hwnd,0,g_hInst,0);	
			stusoclbl = CreateWindow("Static","Social Sec #:",WS_CHILD | WS_VISIBLE,25,200,100,25,hwnd,0,g_hInst,0);	
			stuparlbl = CreateWindow("Static","Parent Id:",WS_CHILD | WS_VISIBLE,25,225,100,25,hwnd,0,g_hInst,0);	

			stuclass1lbl = CreateWindow("Static","Class 1:",WS_CHILD | WS_VISIBLE,350,25,100,25,hwnd,0,g_hInst,0);	
			stugrade1lbl = CreateWindow("Static","Class 1 grade:",WS_CHILD | WS_VISIBLE,350,50,100,25,hwnd,0,g_hInst,0);	
			stuclass2lbl = CreateWindow("Static","Class 2:",WS_CHILD | WS_VISIBLE,350,75,100,25,hwnd,0,g_hInst,0);	
			stugrade2lbl = CreateWindow("Static","Class 2 grade:",WS_CHILD | WS_VISIBLE,350,100,100,25,hwnd,0,g_hInst,0);		
			stuclass3lbl = CreateWindow("Static","Class 3:",WS_CHILD | WS_VISIBLE,350,125,100,25,hwnd,0,g_hInst,0);	
			stugrade3lbl = CreateWindow("Static","Class 3 grade:",WS_CHILD | WS_VISIBLE,350,150,100,25,hwnd,0,g_hInst,0);	
			stuclass4lbl = CreateWindow("Static","Class 4:",WS_CHILD | WS_VISIBLE,350,175,100,25,hwnd,0,g_hInst,0);	
			stugrade4lbl = CreateWindow("Static","Class 4 grade:",WS_CHILD | WS_VISIBLE,350,200,100,25,hwnd,0,g_hInst,0);	
			stuclass5lbl = CreateWindow("Static","Class 5:",WS_CHILD | WS_VISIBLE,350,225,100,25,hwnd,0,g_hInst,0);	
			stugrade5lbl = CreateWindow("Static","Class 5 grade:",WS_CHILD | WS_VISIBLE,350,250,100,25,hwnd,0,g_hInst,0);	
			
			stuacceptl = CreateWindow("Button","Accept",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,250,55,30,hwnd,(HMENU)ID_stuacceptl,g_hInst,0);
			//SetWindowText(edit,"3");
			
			/*		HWND buttonx;
			buttonx = CreateWindow("Button","Ok!",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,200-55,200,100,25,hwnd,(HMENU)ID_BUTTON2,g_hInst,0);
			HWND stx;
			stx = CreateWindow("Static","Example for my friends, you can do what you need with this. :)",WS_CHILD|WS_VISIBLE,5,5,200,150,hwnd,0,g_hInst,0);*/

		}
	    	break;
	case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				{
					switch(LOWORD(wParam))
					{
					case ID_stuacceptl:
						{
							ShowWindow(studentlookupwin,SW_HIDE);
						//hides the window
						ShowWindow(studentmainwin,SW_SHOW);
						//saves the database
						}
						break;					
					}
				}
				break;
			}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}

// about window process
LRESULT APIENTRY teachermainwinProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{

	switch(msg)
	{
	case WM_CLOSE:
		ShowWindow(hwnd,SW_HIDE);
		break;
	case WM_CREATE:
		{

			tchadd = CreateWindow("Button","Add",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,25,55,30,hwnd,(HMENU)ID_tchadd,g_hInst,0);
			tchchange = CreateWindow("Button","Change",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,60,55,30,hwnd,(HMENU)ID_tchCHG,g_hInst,0);
			tchdelete = CreateWindow("Button","Delete",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,95,55,30,hwnd,(HMENU)ID_tchDLT,g_hInst,0);
			tchlookup = CreateWindow("Button","Lookup",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,130,55,30,hwnd,(HMENU)ID_tchLKP,g_hInst,0);
			tchback = CreateWindow("Button","Back",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,165,55,30,hwnd,(HMENU)ID_tchBACK,g_hInst,0);
			tchtxt = CreateWindow("Edit","",WS_BORDER | WS_CHILD | WS_VISIBLE ,100,28,150,20,hwnd,(HMENU)ID_tchTXT,g_hInst,0);
			
			
			/*		HWND buttonx;
			buttonx = CreateWindow("Button","Ok!",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,200-55,200,100,25,hwnd,(HMENU)ID_BUTTON2,g_hInst,0);
			HWND stx;
			stx = CreateWindow("Static","Example for my friends, you can do what you need with this. :)",WS_CHILD|WS_VISIBLE,5,5,200,150,hwnd,0,g_hInst,0);*/

		}
	    	break;
	case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				{
					switch(LOWORD(wParam))
					{
					case ID_tchadd:
						{
							ShowWindow(teachermainwin,SW_HIDE);
						////hides the window
						ShowWindow(teacheraddwin,SW_SHOW);
						}
						break;
						case ID_tchCHG:
						{
							ShowWindow(teachermainwin,SW_HIDE);
						////hides the window
						ShowWindow(teacherchangewin,SW_SHOW);
						}
						break;
						case ID_tchDLT:
						{
							//delete from hash and index
							MessageBox(0,"Record was deleted","Mainmenu",MB_OK|MB_ICONINFORMATION);
							break;
						}
						break;
						case ID_tchLKP:
						{
							ShowWindow(teachermainwin,SW_HIDE);
						////hides the window
						ShowWindow(teacherlookupwin,SW_SHOW);
						}
						break;
						case ID_tchBACK:
						{
						ShowWindow(teachermainwin,SW_HIDE);
						////hides the window
						ShowWindow(mainmenuwin,SW_SHOW);
						//saves the database
						}
						break;
					}
				}
				break;
			}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}
LRESULT APIENTRY teacheraddwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	
	switch(msg)
	{
	case WM_CLOSE:
		ShowWindow(hwnd,SW_HIDE);
		break;
	case WM_CREATE:
		{
			vector<teacherType> teacheradd;	
			tchidtxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,25,175,20,hwnd,(HMENU)ID_tchidtxt,g_hInst,0);
			tchfnametxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,50,175,20,hwnd,(HMENU)ID_tchfnametxt,g_hInst,0);
			tchlnametxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,75,175,20,hwnd,(HMENU)ID_tchlnametxt,g_hInst,0);
			tchemailtxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,100,175,20,hwnd,(HMENU)ID_tchemailtxt,g_hInst,0);
			tchphonetxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,125,175,20,hwnd,(HMENU)ID_tchphonetxt,g_hInst,0);
			
			tchaccept = CreateWindow("Button","Accept",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,165,55,30,hwnd,(HMENU)ID_tchaccept,g_hInst,0);
			
			tchid = CreateWindow("Static","Teacher Id:",WS_CHILD | WS_VISIBLE,25,25,100,25,hwnd,0,g_hInst,0);	
			tchfname = CreateWindow("Static","First Name:",WS_CHILD | WS_VISIBLE,25,50,100,25,hwnd,0,g_hInst,0);	
			tchlname = CreateWindow("Static","Last Name:",WS_CHILD | WS_VISIBLE,25,75,100,25,hwnd,0,g_hInst,0);	
			tchemail = CreateWindow("Static","Email:",WS_CHILD | WS_VISIBLE,25,100,100,25,hwnd,0,g_hInst,0);	
			tchphone = CreateWindow("Static","Phone:",WS_CHILD | WS_VISIBLE,25,125,100,25,hwnd,0,g_hInst,0);	
			
			
			/*		HWND buttonx;
			buttonx = CreateWindow("Button","Ok!",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,200-55,200,100,25,hwnd,(HMENU)ID_BUTTON2,g_hInst,0);
			HWND stx;
			stx = CreateWindow("Static","Example for my friends, you can do what you need with this. :)",WS_CHILD|WS_VISIBLE,5,5,200,150,hwnd,0,g_hInst,0);*/

		}
	    	break;
	case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				{
					switch(LOWORD(wParam))
					{
					case ID_tchaccept:
						{
							ShowWindow(teacheraddwin,SW_HIDE);
						//hides the window
						ShowWindow(teachermainwin,SW_SHOW);
						//saves the database
						}
						break;
					}
				}
				break;
			}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}

LRESULT APIENTRY teacherchangewindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	
		switch(msg)
	{
	case WM_CLOSE:
		ShowWindow(hwnd,SW_HIDE);
		break;
	case WM_CREATE:
		{

			tchidctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,25,175,20,hwnd,(HMENU)ID_tchidctxtc,g_hInst,0);
			tchfnamectxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,50,175,20,hwnd,(HMENU)ID_tchfnamectxtc,g_hInst,0);
			tchlnamectxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,75,175,20,hwnd,(HMENU)ID_tchlnamectxtc,g_hInst,0);
			tchemailctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,100,175,20,hwnd,(HMENU)ID_tchemailctxtc,g_hInst,0);
			tchphonectxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,125,175,20,hwnd,(HMENU)ID_tchphonetxtc,g_hInst,0);
			
			tchacceptc = CreateWindow("Button","Accept",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,165,55,30,hwnd,(HMENU)ID_tchacceptc,g_hInst,0);
			
			tchidc = CreateWindow("Static","Teacher Id:",WS_CHILD | WS_VISIBLE,25,25,100,25,hwnd,0,g_hInst,0);	
			tchfnamec = CreateWindow("Static","First Name:",WS_CHILD | WS_VISIBLE,25,50,100,25,hwnd,0,g_hInst,0);	
			tchlnamec = CreateWindow("Static","Last Name:",WS_CHILD | WS_VISIBLE,25,75,100,25,hwnd,0,g_hInst,0);	
			tchemailc = CreateWindow("Static","Email:",WS_CHILD | WS_VISIBLE,25,100,100,25,hwnd,0,g_hInst,0);	
			tchphonec = CreateWindow("Static","Phone:",WS_CHILD | WS_VISIBLE,25,125,100,25,hwnd,0,g_hInst,0);	
			//SetWindowText(edit,"3");
			
			/*		HWND buttonx;
			buttonx = CreateWindow("Button","Ok!",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,200-55,200,100,25,hwnd,(HMENU)ID_BUTTON2,g_hInst,0);
			HWND stx;
			stx = CreateWindow("Static","Example for my friends, you can do what you need with this. :)",WS_CHILD|WS_VISIBLE,5,5,200,150,hwnd,0,g_hInst,0);*/

		}
	    	break;
	case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				{
					switch(LOWORD(wParam))
					{
					case ID_tchacceptc:
						{
							ShowWindow(teacherchangewin,SW_HIDE);
						//hides the window
						ShowWindow(teachermainwin,SW_SHOW);
						//saves the database
						}
						break;
					}
				}
				break;
			}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}
LRESULT APIENTRY teacherlookupwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	
	switch(msg)
	{
	case WM_CLOSE:
		ShowWindow(hwnd,SW_HIDE);
		break;
	case WM_CREATE:
		{


			tchidlbl = CreateWindow("Static","Teacher Id:",WS_CHILD | WS_VISIBLE,25,25,100,25,hwnd,0,g_hInst,0);	
			tchfnamelbl = CreateWindow("Static","First Name:",WS_CHILD | WS_VISIBLE,25,50,100,25,hwnd,0,g_hInst,0);	
			tchlnamelbl = CreateWindow("Static","Last Name:",WS_CHILD | WS_VISIBLE,25,75,100,25,hwnd,0,g_hInst,0);	
			tchemaillbl = CreateWindow("Static","Email:",WS_CHILD | WS_VISIBLE,25,100,100,25,hwnd,0,g_hInst,0);	
			tchphonelbl= CreateWindow("Static","Phone:",WS_CHILD | WS_VISIBLE,25,125,100,25,hwnd,0,g_hInst,0);	
			tchacceptl = CreateWindow("Button","Accept",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,165,55,30,hwnd,(HMENU)ID_tchacceptl,g_hInst,0);
			//SetWindowText(edit,"3");
			
			/*		HWND buttonx;
			buttonx = CreateWindow("Button","Ok!",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,200-55,200,100,25,hwnd,(HMENU)ID_BUTTON2,g_hInst,0);
			HWND stx;
			stx = CreateWindow("Static","Example for my friends, you can do what you need with this. :)",WS_CHILD|WS_VISIBLE,5,5,200,150,hwnd,0,g_hInst,0);*/

		}
	    	break;
	case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				{
					switch(LOWORD(wParam))
					{
					case ID_tchacceptl:
						{
							ShowWindow(teacherlookupwin,SW_HIDE);
						//hides the window
						ShowWindow(teachermainwin,SW_SHOW);
						//saves the database
						}
						break;					
					}
				}
				break;
			}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}

LRESULT APIENTRY coursemainwinProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{

	switch(msg)
	{
	case WM_CLOSE:
		ShowWindow(hwnd,SW_HIDE);
		break;
	case WM_CREATE:
		{

			crsadd = CreateWindow("Button","Add",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,25,55,30,hwnd,(HMENU)ID_crsadd,g_hInst,0);
			crschange = CreateWindow("Button","Change",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,60,55,30,hwnd,(HMENU)ID_crsCHG,g_hInst,0);
			crsdelete = CreateWindow("Button","Delete",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,95,55,30,hwnd,(HMENU)ID_crsDLT,g_hInst,0);
			crslookup = CreateWindow("Button","Lookup",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,130,55,30,hwnd,(HMENU)ID_crsLKP,g_hInst,0);
			crsback = CreateWindow("Button","Back",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,165,55,30,hwnd,(HMENU)ID_crsBACK,g_hInst,0);
			crstxt = CreateWindow("Edit","",WS_BORDER | WS_CHILD | WS_VISIBLE ,100,28,150,20,hwnd,(HMENU)ID_crsTXT,g_hInst,0);
			
			
			/*		HWND buttonx;
			buttonx = CreateWindow("Button","Ok!",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,200-55,200,100,25,hwnd,(HMENU)ID_BUTTON2,g_hInst,0);
			HWND stx;
			stx = CreateWindow("Static","Example for my friends, you can do what you need with this. :)",WS_CHILD|WS_VISIBLE,5,5,200,150,hwnd,0,g_hInst,0);*/

		}
	    	break;
	case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				{
					switch(LOWORD(wParam))
					{
					case ID_crsadd:
						{
							ShowWindow(coursemainwin,SW_HIDE);
						////hides the window
						ShowWindow(courseaddwin,SW_SHOW);
						}
						break;
						case ID_crsCHG:
						{
							ShowWindow(coursemainwin,SW_HIDE);
						////hides the window
						ShowWindow(coursechangewin,SW_SHOW);
						}
						break;
						case ID_crsDLT:
						{
							//delete from hash and index
							MessageBox(0,"Record was deleted","Mainmenu",MB_OK|MB_ICONINFORMATION);
							break;
						}
						break;
						case ID_crsLKP:
						{
							ShowWindow(coursemainwin,SW_HIDE);
						////hides the window
						ShowWindow(courselookupwin,SW_SHOW);
						}
						break;
						case ID_crsBACK:
						{
						ShowWindow(coursemainwin,SW_HIDE);
						////hides the window
						ShowWindow(mainmenuwin,SW_SHOW);
						//saves the database
						}
						break;
					}
				}
				break;
			}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}
LRESULT APIENTRY courseaddwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	
	switch(msg)
	{
	case WM_CLOSE:
		ShowWindow(hwnd,SW_HIDE);
		break;
	case WM_CREATE:
		{
			crsidtxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,25,175,20,hwnd,(HMENU)ID_crsidtxt,g_hInst,0);
			crsnametxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,50,175,20,hwnd,(HMENU)ID_crsnametxt,g_hInst,0);
			crsdesctxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,75,175,20,hwnd,(HMENU)ID_crsdesctxt,g_hInst,0);
			
			crsaccept = CreateWindow("Button","Accept",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,165,55,30,hwnd,(HMENU)ID_crsaccept,g_hInst,0);
			
			crsid = CreateWindow("Static","Course Id:",WS_CHILD | WS_VISIBLE,25,25,100,25,hwnd,0,g_hInst,0);	
			crsname = CreateWindow("Static","Name:",WS_CHILD | WS_VISIBLE,25,50,100,25,hwnd,0,g_hInst,0);	
			crsdesc = CreateWindow("Static","Description:",WS_CHILD | WS_VISIBLE,25,75,100,25,hwnd,0,g_hInst,0);	
		
			/*		HWND buttonx;
			buttonx = CreateWindow("Button","Ok!",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,200-55,200,100,25,hwnd,(HMENU)ID_BUTTON2,g_hInst,0);
			HWND stx;
			stx = CreateWindow("Static","Example for my friends, you can do what you need with this. :)",WS_CHILD|WS_VISIBLE,5,5,200,150,hwnd,0,g_hInst,0);*/

		}
	    	break;
	case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				{
					switch(LOWORD(wParam))
					{
					case ID_crsaccept:
						{
							ShowWindow(courseaddwin,SW_HIDE);
						//hides the window
						ShowWindow(coursemainwin,SW_SHOW);
						//saves the database
						}
						break;
					}
				}
				break;
			}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}

LRESULT APIENTRY coursechangewindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	
		switch(msg)
	{
	case WM_CLOSE:
		ShowWindow(hwnd,SW_HIDE);
		break;
	case WM_CREATE:
		{

			crsidctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,25,175,20,hwnd,(HMENU)ID_crsidctxtc,g_hInst,0);
			crsnamectxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,50,175,20,hwnd,(HMENU)ID_crsnamectxtc,g_hInst,0);
			crsdescctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,75,175,20,hwnd,(HMENU)ID_crsdescctxtc,g_hInst,0);
			
			crsacceptc = CreateWindow("Button","Accept",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,165,55,30,hwnd,(HMENU)ID_crsacceptc,g_hInst,0);
			
			crsidc = CreateWindow("Static","Course Id:",WS_CHILD | WS_VISIBLE,25,25,100,25,hwnd,0,g_hInst,0);	
			crsnamec = CreateWindow("Static","Name:",WS_CHILD | WS_VISIBLE,25,50,100,25,hwnd,0,g_hInst,0);	
			crsdescc = CreateWindow("Static","Description:",WS_CHILD | WS_VISIBLE,25,75,100,25,hwnd,0,g_hInst,0);	
		
			//SetWindowText(edit,"3");
			
			/*		HWND buttonx;
			buttonx = CreateWindow("Button","Ok!",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,200-55,200,100,25,hwnd,(HMENU)ID_BUTTON2,g_hInst,0);
			HWND stx;
			stx = CreateWindow("Static","Example for my friends, you can do what you need with this. :)",WS_CHILD|WS_VISIBLE,5,5,200,150,hwnd,0,g_hInst,0);*/

		}
	    	break;
	case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				{
					switch(LOWORD(wParam))
					{
					case ID_crsacceptc:
						{
							ShowWindow(coursechangewin,SW_HIDE);
						//hides the window
						ShowWindow(coursemainwin,SW_SHOW);
						//saves the database
						}
						break;
					}
				}
				break;
			}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}
LRESULT APIENTRY courselookupwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	
	switch(msg)
	{
	case WM_CLOSE:
		ShowWindow(hwnd,SW_HIDE);
		break;
	case WM_CREATE:
		{

			crsidlbl = CreateWindow("Static","Course Id:",WS_CHILD | WS_VISIBLE,25,25,100,25,hwnd,0,g_hInst,0);	
			crsnamelbl = CreateWindow("Static","Name:",WS_CHILD | WS_VISIBLE,25,50,100,25,hwnd,0,g_hInst,0);	
			crsdesclbl = CreateWindow("Static","Description:",WS_CHILD | WS_VISIBLE,25,75,100,25,hwnd,0,g_hInst,0);

			crsacceptl = CreateWindow("Button","Accept",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,165,55,30,hwnd,(HMENU)ID_crsacceptl,g_hInst,0);
			//SetWindowText(edit,"3");
			
			/*		HWND buttonx;
			buttonx = CreateWindow("Button","Ok!",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,200-55,200,100,25,hwnd,(HMENU)ID_BUTTON2,g_hInst,0);
			HWND stx;
			stx = CreateWindow("Static","Example for my friends, you can do what you need with this. :)",WS_CHILD|WS_VISIBLE,5,5,200,150,hwnd,0,g_hInst,0);*/

		}
	    	break;
	case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				{
					switch(LOWORD(wParam))
					{
					case ID_crsacceptl:
						{
							ShowWindow(courselookupwin,SW_HIDE);
						//hides the window
						ShowWindow(coursemainwin,SW_SHOW);
						//saves the database
						}
						break;					
					}
				}
				break;
			}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}

LRESULT APIENTRY contactmainwinProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{

	switch(msg)
	{
	case WM_CLOSE:
		ShowWindow(hwnd,SW_HIDE);
		break;
	case WM_CREATE:
		{

			conadd = CreateWindow("Button","Add",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,25,55,30,hwnd,(HMENU)ID_conadd,g_hInst,0);
			conchange = CreateWindow("Button","Change",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,60,55,30,hwnd,(HMENU)ID_conCHG,g_hInst,0);
			condelete = CreateWindow("Button","Delete",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,95,55,30,hwnd,(HMENU)ID_conDLT,g_hInst,0);
			conlookup = CreateWindow("Button","Lookup",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,130,55,30,hwnd,(HMENU)ID_conLKP,g_hInst,0);
			conback = CreateWindow("Button","Back",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,165,55,30,hwnd,(HMENU)ID_conBACK,g_hInst,0);
			contxt = CreateWindow("Edit","",WS_BORDER | WS_CHILD | WS_VISIBLE ,100,28,150,20,hwnd,(HMENU)ID_conTXT,g_hInst,0);
			
			
			/*		HWND buttonx;
			buttonx = CreateWindow("Button","Ok!",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,200-55,200,100,25,hwnd,(HMENU)ID_BUTTON2,g_hInst,0);
			HWND stx;
			stx = CreateWindow("Static","Example for my friends, you can do what you need with this. :)",WS_CHILD|WS_VISIBLE,5,5,200,150,hwnd,0,g_hInst,0);*/

		}
	    	break;
	case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				{
					switch(LOWORD(wParam))
					{
					case ID_conadd:
						{
							ShowWindow(contactmainwin,SW_HIDE);
						////hides the window
						ShowWindow(contactaddwin,SW_SHOW);
						}
						break;
						case ID_conCHG:
						{
							ShowWindow(contactmainwin,SW_HIDE);
						////hides the window
						ShowWindow(contactchangewin,SW_SHOW);
						}
						break;
						case ID_conDLT:
						{
							//delete from hash and index
							MessageBox(0,"Record was deleted","Mainmenu",MB_OK|MB_ICONINFORMATION);
							break;
						}
						break;
						case ID_conLKP:
						{
							ShowWindow(contactmainwin,SW_HIDE);
						////hides the window
						ShowWindow(contactlookupwin,SW_SHOW);
						}
						break;
						case ID_conBACK:
						{
						ShowWindow(contactmainwin,SW_HIDE);
						////hides the window
						ShowWindow(mainmenuwin,SW_SHOW);
						//saves the database
						}
						break;
					}
				}
				break;
			}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}
LRESULT APIENTRY contactaddwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	
	switch(msg)
	{
	case WM_CLOSE:
		ShowWindow(hwnd,SW_HIDE);
		break;
	case WM_CREATE:
		{
			conidtxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,25,175,20,hwnd,(HMENU)ID_conidtxt,g_hInst,0);
			confnametxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,50,175,20,hwnd,(HMENU)ID_confnametxt,g_hInst,0);
			conlnametxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,75,175,20,hwnd,(HMENU)ID_conlnametxt,g_hInst,0);
			conphonetxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,100,175,20,hwnd,(HMENU)ID_conphonetxt,g_hInst,0);
			conaddresstxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,125,175,20,hwnd,(HMENU)ID_conphonetxt,g_hInst,0);
			conziptxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,150,175,20,hwnd,(HMENU)ID_conphonetxt,g_hInst,0);
			constatetxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,175,175,20,hwnd,(HMENU)ID_conphonetxt,g_hInst,0);
			conemailtxt = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,200,175,20,hwnd,(HMENU)ID_conemailtxt,g_hInst,0);

			conaccept = CreateWindow("Button","Accept",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,225,55,30,hwnd,(HMENU)ID_conaccept,g_hInst,0);
			
			conid = CreateWindow("Static","Contact Id:",WS_CHILD | WS_VISIBLE,25,25,100,25,hwnd,0,g_hInst,0);	
			confname = CreateWindow("Static","First Name:",WS_CHILD | WS_VISIBLE,25,50,100,25,hwnd,0,g_hInst,0);	
			conlname = CreateWindow("Static","Last Name:",WS_CHILD | WS_VISIBLE,25,75,100,25,hwnd,0,g_hInst,0);	
			conphone = CreateWindow("Static","Phone:",WS_CHILD | WS_VISIBLE,25,100,100,25,hwnd,0,g_hInst,0);
			conaddress = CreateWindow("Static","Address:",WS_CHILD | WS_VISIBLE,25,125,100,25,hwnd,0,g_hInst,0);
			conzip = CreateWindow("Static","Zip:",WS_CHILD | WS_VISIBLE,25,150,100,25,hwnd,0,g_hInst,0);
			constate = CreateWindow("Static","State:",WS_CHILD | WS_VISIBLE,25,175,100,25,hwnd,0,g_hInst,0);
			conemail = CreateWindow("Static","Email:",WS_CHILD | WS_VISIBLE,25,200,100,25,hwnd,0,g_hInst,0);
			
			
			
			/*		HWND buttonx;
			buttonx = CreateWindow("Button","Ok!",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,200-55,200,100,25,hwnd,(HMENU)ID_BUTTON2,g_hInst,0);
			HWND stx;
			stx = CreateWindow("Static","Example for my friends, you can do what you need with this. :)",WS_CHILD|WS_VISIBLE,5,5,200,150,hwnd,0,g_hInst,0);*/

		}
	    	break;
	case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				{
					switch(LOWORD(wParam))
					{
					case ID_conaccept:
						{
							ShowWindow(contactaddwin,SW_HIDE);
						//hides the window
						ShowWindow(contactmainwin,SW_SHOW);
						//saves the database
						}
						break;
					}
				}
				break;
			}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}

LRESULT APIENTRY contactchangewindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	
		switch(msg)
	{
	case WM_CLOSE:
		ShowWindow(hwnd,SW_HIDE);
		break;
	case WM_CREATE:
		{

			conidctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,25,175,20,hwnd,(HMENU)ID_conidtxtc,g_hInst,0);
			confnamectxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,50,175,20,hwnd,(HMENU)ID_confnametxtc,g_hInst,0);
			conlnamectxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,75,175,20,hwnd,(HMENU)ID_conlnametxtc,g_hInst,0);
			conemailctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,100,175,20,hwnd,(HMENU)ID_conphonetxtc,g_hInst,0);
			conaddresstxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,125,175,20,hwnd,(HMENU)ID_conphonetxtc,g_hInst,0);
			conziptxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,150,175,20,hwnd,(HMENU)ID_conphonetxtc,g_hInst,0);
			constatetxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,175,175,20,hwnd,(HMENU)ID_conphonetxtc,g_hInst,0);
			conemailctxtc = CreateWindow("Edit", NULL,WS_BORDER | NULL | WS_CHILD | WS_VISIBLE | NULL | NULL ,150,200,175,20,hwnd,(HMENU)ID_conemailtxtc,g_hInst,0);

			conidc = CreateWindow("Static","Contact Id:",WS_CHILD | WS_VISIBLE,25,25,100,25,hwnd,0,g_hInst,0);	
			confnamec = CreateWindow("Static","First Name:",WS_CHILD | WS_VISIBLE,25,50,100,25,hwnd,0,g_hInst,0);	
			conlnamec = CreateWindow("Static","Last Name:",WS_CHILD | WS_VISIBLE,25,75,100,25,hwnd,0,g_hInst,0);	
			conphonec = CreateWindow("Static","Phone:",WS_CHILD | WS_VISIBLE,25,100,100,25,hwnd,0,g_hInst,0);
			conaddressc = CreateWindow("Static","Address:",WS_CHILD | WS_VISIBLE,25,125,100,25,hwnd,0,g_hInst,0);
			conzipc = CreateWindow("Static","Zip:",WS_CHILD | WS_VISIBLE,25,150,100,25,hwnd,0,g_hInst,0);
			constatec = CreateWindow("Static","State:",WS_CHILD | WS_VISIBLE,25,175,100,25,hwnd,0,g_hInst,0);
			conemailc = CreateWindow("Static","Email:",WS_CHILD | WS_VISIBLE,25,200,100,25,hwnd,0,g_hInst,0);
			
			conacceptc = CreateWindow("Button","Accept",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,225,55,30,hwnd,(HMENU)ID_conacceptc,g_hInst,0);	
			
			//SetWindowText(edit,"3");
			
			/*		HWND buttonx;
			buttonx = CreateWindow("Button","Ok!",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,200-55,200,100,25,hwnd,(HMENU)ID_BUTTON2,g_hInst,0);
			HWND stx;
			stx = CreateWindow("Static","Example for my friends, you can do what you need with this. :)",WS_CHILD|WS_VISIBLE,5,5,200,150,hwnd,0,g_hInst,0);*/

		}
	    	break;
	case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				{
					switch(LOWORD(wParam))
					{
					case ID_conacceptc:
						{
							ShowWindow(contactchangewin,SW_HIDE);
						//hides the window
						ShowWindow(contactmainwin,SW_SHOW);
						//saves the database
						}
						break;
					}
				}
				break;
			}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}
LRESULT APIENTRY contactlookupwindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	
	switch(msg)
	{
	case WM_CLOSE:
		ShowWindow(hwnd,SW_HIDE);
		break;
	case WM_CREATE:
		{

			conidlbl = CreateWindow("Static","Contact Id:",WS_CHILD | WS_VISIBLE,25,25,100,25,hwnd,0,g_hInst,0);	
			confnamelbl = CreateWindow("Static","First Name:",WS_CHILD | WS_VISIBLE,25,50,100,25,hwnd,0,g_hInst,0);	
			conlnamelbl = CreateWindow("Static","Last Name:",WS_CHILD | WS_VISIBLE,25,75,100,25,hwnd,0,g_hInst,0);	
			conphonelbl = CreateWindow("Static","Phone:",WS_CHILD | WS_VISIBLE,25,100,100,25,hwnd,0,g_hInst,0);
			conaddresslbl = CreateWindow("Static","Address:",WS_CHILD | WS_VISIBLE,25,125,100,25,hwnd,0,g_hInst,0);
			conziplbl = CreateWindow("Static","Zip:",WS_CHILD | WS_VISIBLE,25,150,100,25,hwnd,0,g_hInst,0);
			constatelbl = CreateWindow("Static","State:",WS_CHILD | WS_VISIBLE,25,175,100,25,hwnd,0,g_hInst,0);
			conemaillbl = CreateWindow("Static","Email:",WS_CHILD | WS_VISIBLE,25,200,100,25,hwnd,0,g_hInst,0);
			
			conacceptl = CreateWindow("Button","Accept",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,25,225,55,30,hwnd,(HMENU)ID_conacceptl,g_hInst,0);
			//SetWindowText(edit,"3");
			
			/*		HWND buttonx;
			buttonx = CreateWindow("Button","Ok!",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,200-55,200,100,25,hwnd,(HMENU)ID_BUTTON2,g_hInst,0);
			HWND stx;
			stx = CreateWindow("Static","Example for my friends, you can do what you need with this. :)",WS_CHILD|WS_VISIBLE,5,5,200,150,hwnd,0,g_hInst,0);*/

		}
	    	break;
	case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				{
					switch(LOWORD(wParam))
					{
					case ID_conacceptl:
						{
							ShowWindow(contactlookupwin,SW_HIDE);
						//hides the window
						ShowWindow(contactmainwin,SW_SHOW);
						//saves the database
						}
						break;					
					}
				}
				break;
			}

		}
		break;
	default: return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}
#pragma endregion