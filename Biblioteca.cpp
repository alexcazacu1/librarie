#include <windows.h>
#include<CommCtrl.h>
#define ADD_BUTTON	101	// Button identifier
#define EDIT_BUTTON	102
#define DEL_BUTTON	103
#define SRC_BUTTON	104
#define IDC_MAIN_LIST  105 // Edit box identifier
#define ADD_WND  106 
#define ADD_BUTTON2 107
#define DEL_BUTTON2 108
#define ADD_EDITN2 1007
#define ADD_EDITP2 1008
#define ADD_EDITC2 1009
#define ADD_EDITN3 1010
#define ADD_EDITP3 1011
#define ADD_EDITC3 1012
#define ADD_EDITN4 1013
#define ADD_EDITP4 1014
#define ADD_EDITN5 1015
#define ADD_EDITP5 1016
#define ADD_EDITC5 1017
HWND hEdit, hList,hAddN,hAddP,hAddC,hDelN, hDelP, hSrcC, hSrcN, hSrcP;
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK windowprocessforwindow2(HWND handleforwindow1, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK windowprocessforwindow3(HWND handleforwindow1, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK windowprocessforwindow4(HWND handleforwindow1, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK windowprocessforwindow5(HWND handleforwindow1, UINT message, WPARAM wParam, LPARAM lParam);
bool nume2, prenume2, carte2, nume3, prenume3, carte3, nume4, prenume4, nume5, prenume5, carte5 = false;
bool window1open, window2open, window3open, window4open, window5open = false;
bool windowclass1registeredbefore, windowclass2registeredbefore,
windowclass3registeredbefore, windowclass4registeredbefore, windowclass5registeredbefore = false;

enum windowtoopenenumt { none, window2, window3, window4, window5 };

windowtoopenenumt windowtoopenenum = none;

void createwindow2(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindow3(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindow4(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindow5(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nShowCmd)
{
	bool endprogram = false;
	WNDCLASSEX windowclassforwindow2;
	WNDCLASSEX windowclassforwindow3;
	WNDCLASSEX windowclassforwindow4;
	WNDCLASSEX windowclassforwindow5;
	HWND handleforwindow2;
	HWND handleforwindow3;
	HWND handleforwindow4;
	HWND handleforwindow5;

	WNDCLASSEX wClass;
	ZeroMemory(&wClass, sizeof(WNDCLASSEX));
	wClass.cbClsExtra = NULL;
	wClass.cbSize = sizeof(WNDCLASSEX);
	wClass.cbWndExtra = NULL;
	wClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wClass.hIcon = NULL;
	wClass.hIconSm = NULL;
	wClass.hInstance = hInst;
	wClass.lpfnWndProc = (WNDPROC)WinProc;
	wClass.lpszClassName = "Window Class";
	wClass.lpszMenuName = NULL;
	wClass.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wClass))
	{
		int nResult = GetLastError();
		MessageBox(NULL,
			"Window class creation failed\r\n",
			"Window Class Failed",
			MB_ICONERROR);
	}

	HWND hWnd = CreateWindowEx(NULL,
		"Window Class",
		"Librarie",
		WS_OVERLAPPEDWINDOW | WS_BORDER,
		200,
		0,
		430,
		730,
		NULL,
		NULL,
		hInst,
		NULL);

	if (!hWnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			"Window creation failed\r\n",
			"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hWnd, nShowCmd);
	MSG msg;
	bool endloop = false;
	while (endloop == false) {
		if (GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (windowtoopenenum != none) {
			switch (windowtoopenenum) {
			case window2:
				if (window2open == false) {
					createwindow2(windowclassforwindow2, handleforwindow2, hInst, nShowCmd);
				}
				break;
			case window3:
				if (window3open == false) {
					createwindow3(windowclassforwindow3, handleforwindow3, hInst, nShowCmd);
				}
				break;
			case window4:
				if (window4open == false) {
					createwindow4(windowclassforwindow4, handleforwindow4, hInst, nShowCmd);
				}
				break;
			case window5:
				if (window5open == false) {
					createwindow5(windowclassforwindow5, handleforwindow5, hInst, nShowCmd);
				}
				break;
			}
			windowtoopenenum = none;
		}
		if (window1open == false && window2open == false && window3open == false && window4open == false && window5open == false)
			endloop = true;
	}

MessageBox(NULL,
	"All windows are closed.  Program will now close.",
	"Exit",
	MB_ICONINFORMATION);

}
void createwindow2(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd) {
	if (windowclass2registeredbefore == false) {
		ZeroMemory(&wc, sizeof(WNDCLASSEX));
		wc.cbClsExtra = NULL;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.cbWndExtra = NULL;
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hIcon = NULL;
		wc.hIconSm = NULL;
		wc.hInstance = hInst;
		wc.lpfnWndProc = (WNDPROC)windowprocessforwindow2;
		wc.lpszClassName = "wc2";
		wc.lpszMenuName = NULL;
		wc.style = CS_HREDRAW | CS_VREDRAW;

		if (!RegisterClassEx(&wc))
		{
			int nResult = GetLastError();
			MessageBox(NULL,
				"Window class creation failed",
				"Window Class Failed",
				MB_ICONERROR);
		}
		else
			windowclass2registeredbefore = true;
	}
	hwnd = CreateWindowEx(NULL,
		wc.lpszClassName,
		"Adaugare Client",
		WS_OVERLAPPEDWINDOW,
		630,
		100,
		250,
		130,
		NULL,
		NULL,
		hInst,
		NULL                /* No Window Creation data */
	);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			"Window creation failed",
			"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}
void createwindow3(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd) {
	if (windowclass3registeredbefore == false) {
		ZeroMemory(&wc, sizeof(WNDCLASSEX));
		wc.cbClsExtra = NULL;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.cbWndExtra = NULL;
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hIcon = NULL;
		wc.hIconSm = NULL;
		wc.hInstance = hInst;
		wc.lpfnWndProc = (WNDPROC)windowprocessforwindow3;
		wc.lpszClassName = "window class 3";
		wc.lpszMenuName = NULL;
		wc.style = CS_HREDRAW | CS_VREDRAW;

		if (!RegisterClassEx(&wc))
		{
			int nResult = GetLastError();
			MessageBox(NULL,
				"Window class creation failed",
				"Window Class Failed",
				MB_ICONERROR);
		}
		else
			windowclass3registeredbefore = true;
	}
	hwnd = CreateWindowEx(NULL,
		wc.lpszClassName,
		"Adaugare Carte",
		WS_OVERLAPPEDWINDOW,
		630,
		100,
		250,
		130,
		NULL,
		NULL,
		hInst,
		NULL               
	);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			"Window creation failed",
			"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}

void createwindow4(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd) {
	if (windowclass4registeredbefore == false) {
		ZeroMemory(&wc, sizeof(WNDCLASSEX));
		wc.cbClsExtra = NULL;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.cbWndExtra = NULL;
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hIcon = NULL;
		wc.hIconSm = NULL;
		wc.hInstance = hInst;
		wc.lpfnWndProc = (WNDPROC)windowprocessforwindow4;
		wc.lpszClassName = "window class 4";
		wc.lpszMenuName = NULL;
		wc.style = CS_HREDRAW | CS_VREDRAW;

		if (!RegisterClassEx(&wc))
		{
			int nResult = GetLastError();
			MessageBox(NULL,
				"Window class creation failed",
				"Window Class Failed",
				MB_ICONERROR);
		}
		else
			windowclass4registeredbefore = true;
	}
	hwnd = CreateWindowEx(NULL,
		wc.lpszClassName,
		"Stergere Client",
		WS_OVERLAPPEDWINDOW,
		630,
		100,
		250,
		130,
		NULL,
		NULL,
		hInst,
		NULL                /* No Window Creation data */
	);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			"Window creation failed",
			"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}
void createwindow5(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd) {
	if (windowclass5registeredbefore == false) {
		ZeroMemory(&wc, sizeof(WNDCLASSEX));
		wc.cbClsExtra = NULL;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.cbWndExtra = NULL;
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hIcon = NULL;
		wc.hIconSm = NULL;
		wc.hInstance = hInst;
		wc.lpfnWndProc = (WNDPROC)windowprocessforwindow5;
		wc.lpszClassName = "window class 5";
		wc.lpszMenuName = NULL;
		wc.style = CS_HREDRAW | CS_VREDRAW;

		if (!RegisterClassEx(&wc))
		{
			int nResult = GetLastError();
			MessageBox(NULL,
				"Window class creation failed",
				"Window Class Failed",
				MB_ICONERROR);
		}
		else
			windowclass5registeredbefore = true;
	}
	hwnd = CreateWindowEx(NULL,
		wc.lpszClassName,
		"Cautare",
		WS_OVERLAPPEDWINDOW,
		630,
		100,
		490,
		130,
		NULL,
		NULL,
		hInst,
		NULL                /* No Window Creation data */
	);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			"Window creation failed",
			"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}
LRESULT CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
	{
		window1open = true;
		// Create an list box
		hList = CreateWindowEx(WS_EX_CLIENTEDGE,
			"LISTBOX",
			"",
			WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS,
			3,
			32,
			410,
			660,
			hWnd,
			(HMENU)IDC_MAIN_LIST,
			GetModuleHandle(NULL),
			NULL);
		HGDIOBJ hfDefault = GetStockObject(DEFAULT_GUI_FONT);
		SendMessage(hEdit,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
		SendMessage(hEdit,
			WM_SETTEXT,
			NULL,
			(LPARAM)"");

		// Create a push button
		HWND add_client = CreateWindowEx(NULL,
			"BUTTON",
			"Adauga un client",
			WS_TABSTOP | WS_VISIBLE |
			WS_CHILD | BS_DEFPUSHBUTTON,
			3,
			3,
			100,
			24,
			hWnd,
			(HMENU)ADD_BUTTON,
			GetModuleHandle(NULL),
			NULL);
		SendMessage(add_client,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
		HWND ed_client = CreateWindowEx(NULL,
			"BUTTON",
			"Adauga Carte",
			WS_TABSTOP | WS_VISIBLE |
			WS_CHILD | BS_DEFPUSHBUTTON,
			106,
			3,
			100,
			24,
			hWnd,
			(HMENU)EDIT_BUTTON,
			GetModuleHandle(NULL),
			NULL);
		SendMessage(ed_client,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
		HWND del_client = CreateWindowEx(NULL,
			"BUTTON",
			"Sterge un client",
			WS_TABSTOP | WS_VISIBLE |
			WS_CHILD | BS_DEFPUSHBUTTON,
			209,
			3,
			100,
			24,
			hWnd,
			(HMENU)DEL_BUTTON,
			GetModuleHandle(NULL),
			NULL);
		SendMessage(del_client,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
		HWND cautare = CreateWindowEx(NULL,
			"BUTTON",
			"Cautare",
			WS_TABSTOP | WS_VISIBLE |
			WS_CHILD | BS_DEFPUSHBUTTON,
			312,
			3,
			100,
			24,
			hWnd,
			(HMENU)SRC_BUTTON,
			GetModuleHandle(NULL),
			NULL);
		SendMessage(cautare,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ADD_BUTTON: //sa fac un nou window
		{
			windowtoopenenum = window2;
		}
		break;
		case EDIT_BUTTON:
		{
			windowtoopenenum = window3;
		}
		break;
		case DEL_BUTTON:
		{
			windowtoopenenum = window4;
		}
		break;
		case SRC_BUTTON:
		{
			windowtoopenenum = window5;
		}
		break;
		}
		break;

	case WM_DESTROY:
	{
		window1open = false;
		return 0;
	}
	break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK windowprocessforwindow2(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	if (GetFocus() == hAddN && nume2 == false)
	{
		SendMessage(hAddN,
			WM_SETTEXT,
			NULL,
			(LPARAM)"");
		nume2 = true;
	}
	if (GetFocus() == hAddP && prenume2 == false)
	{
		SendMessage(hAddP,
			WM_SETTEXT,
			NULL,
			(LPARAM)"");
		prenume2 = true;
	}
	if (GetFocus() == hAddC && carte2 == false)
	{
		SendMessage(hAddC,
			WM_SETTEXT,
			NULL,
			(LPARAM)"");
		carte2 = true;
	}
	switch (message) {
	case WM_CREATE:
	{
		// Create an edit box
		hAddN = CreateWindowEx(WS_EX_CLIENTEDGE,
			"EDIT",
			"",
			WS_CHILD | WS_VISIBLE |
			ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
			2,
			2,
			230,
			20,
			hwnd,
			(HMENU)ADD_EDITN2,
			GetModuleHandle(NULL),
			NULL);
		HGDIOBJ hfDefault = GetStockObject(DEFAULT_GUI_FONT);
		SendMessage(hAddN,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
		SendMessage(hAddN,
			WM_SETTEXT,
			NULL,
			(LPARAM)"Nume");
		hAddP = CreateWindowEx(WS_EX_CLIENTEDGE,
			"EDIT",
			"",
			WS_CHILD | WS_VISIBLE |
			ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
			2,
			24,
			230,
			20,
			hwnd,
			(HMENU)ADD_EDITP2,
			GetModuleHandle(NULL),
			NULL);
		hfDefault = GetStockObject(DEFAULT_GUI_FONT);
		SendMessage(hAddP,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
		SendMessage(hAddP,
			WM_SETTEXT,
			NULL,
			(LPARAM)"Prenume");
		hAddC = CreateWindowEx(WS_EX_CLIENTEDGE,
			"EDIT",
			"",
			WS_CHILD | WS_VISIBLE |
			ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
			2,
			44,
			230,
			20,
			hwnd,
			(HMENU)ADD_EDITC2,
			GetModuleHandle(NULL),
			NULL);
		hfDefault = GetStockObject(DEFAULT_GUI_FONT);
		SendMessage(hAddC,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
		SendMessage(hAddC,
			WM_SETTEXT,
			NULL,
			(LPARAM)"Carte");

		// Create a push button
		HWND hWndButton = CreateWindowEx(NULL,
			"BUTTON",
			"Adauga",
			WS_TABSTOP | WS_VISIBLE |
			WS_CHILD | BS_DEFPUSHBUTTON,
			60,
			65,
			100,
			24,
			hwnd,
			(HMENU)ADD_BUTTON2,
			GetModuleHandle(NULL),
			NULL);
		SendMessage(hWndButton,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
	}
	break;
	case WM_DESTROY:
	{	window2open = false;
		nume2 = false;
		prenume2 = false;
		carte2 = false;
	}
		break;
	case WM_COMMAND:
		switch LOWORD(wParam) {
			
			break;
		}
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

LRESULT CALLBACK windowprocessforwindow3(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	if (GetFocus() == hAddN && nume3 == false)
	{
		SendMessage(hAddN,
			WM_SETTEXT,
			NULL,
			(LPARAM)"");
		nume3 = true;
	}
	if (GetFocus() == hAddP && prenume3 == false)
	{
		SendMessage(hAddP,
			WM_SETTEXT,
			NULL,
			(LPARAM)"");
		prenume3 = true;
	}
	if (GetFocus() == hAddC && carte3 == false)
	{
		SendMessage(hAddC,
			WM_SETTEXT,
			NULL,
			(LPARAM)"");
		carte3 = true;
	}
	switch (message) {
	case WM_CREATE:
	{
		// Create an edit box
		hAddN = CreateWindowEx(WS_EX_CLIENTEDGE,
			"EDIT",
			"",
			WS_CHILD | WS_VISIBLE |
			ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
			2,
			2,
			230,
			20,
			hwnd,
			(HMENU)ADD_EDITN3,
			GetModuleHandle(NULL),
			NULL);
		HGDIOBJ hfDefault = GetStockObject(DEFAULT_GUI_FONT);
		SendMessage(hAddN,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
		SendMessage(hAddN,
			WM_SETTEXT,
			NULL,
			(LPARAM)"Nume");
		hAddP = CreateWindowEx(WS_EX_CLIENTEDGE,
			"EDIT",
			"",
			WS_CHILD | WS_VISIBLE |
			ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
			2,
			24,
			230,
			20,
			hwnd,
			(HMENU)ADD_EDITP3,
			GetModuleHandle(NULL),
			NULL);
		hfDefault = GetStockObject(DEFAULT_GUI_FONT);
		SendMessage(hAddP,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
		SendMessage(hAddP,
			WM_SETTEXT,
			NULL,
			(LPARAM)"Prenume");
		hAddC = CreateWindowEx(WS_EX_CLIENTEDGE,
			"EDIT",
			"",
			WS_CHILD | WS_VISIBLE |
			ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
			2,
			44,
			230,
			20,
			hwnd,
			(HMENU)ADD_EDITC3,
			GetModuleHandle(NULL),
			NULL);
		hfDefault = GetStockObject(DEFAULT_GUI_FONT);
		SendMessage(hAddC,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
		SendMessage(hAddC,
			WM_SETTEXT,
			NULL,
			(LPARAM)"Carte");

		// Create a push button
		HWND hWndButton = CreateWindowEx(NULL,
			"BUTTON",
			"Adauga Carte",
			WS_TABSTOP | WS_VISIBLE |
			WS_CHILD | BS_DEFPUSHBUTTON,
			60,
			65,
			100,
			24,
			hwnd,
			(HMENU)ADD_BUTTON2,
			GetModuleHandle(NULL),
			NULL);
		SendMessage(hWndButton,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
	}
		break;
	case WM_DESTROY:
		window3open = false;
		nume3 = false;
		prenume3 = false;
		carte3 = false;
		break;
	case WM_COMMAND:
		switch LOWORD(wParam) {
		
			break;
		}
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

LRESULT CALLBACK windowprocessforwindow4(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	if (GetFocus() == hDelN && nume4 == false)
	{
		SendMessage(hDelN,
			WM_SETTEXT,
			NULL,
			(LPARAM)"");
		nume4 = true;
	}
	if (GetFocus() == hDelP && prenume4 == false)
	{
		SendMessage(hDelP,
			WM_SETTEXT,
			NULL,
			(LPARAM)"");
		prenume4 = true;
	}
	switch (message) {
	case WM_DESTROY:
	{	window4open = false;
		nume4 = false;
		prenume4 = false;
	}
		break;
	case WM_CREATE:
	{
		// Create an edit box
		hDelN = CreateWindowEx(WS_EX_CLIENTEDGE,
			"EDIT",
			"",
			WS_CHILD | WS_VISIBLE |
			ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
			2,
			7,
			230,
			20,
			hwnd,
			(HMENU)ADD_EDITN4,
			GetModuleHandle(NULL),
			NULL);
		HGDIOBJ hfDefault = GetStockObject(DEFAULT_GUI_FONT);
		SendMessage(hDelN,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
		SendMessage(hDelN,
			WM_SETTEXT,
			NULL,
			(LPARAM)"Nume");
		hDelP = CreateWindowEx(WS_EX_CLIENTEDGE,
			"EDIT",
			"",
			WS_CHILD | WS_VISIBLE |
			ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
			2,
			34,
			230,
			20,
			hwnd,
			(HMENU)ADD_EDITP4,
			GetModuleHandle(NULL),
			NULL);
		hfDefault = GetStockObject(DEFAULT_GUI_FONT);
		SendMessage(hDelP,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
		SendMessage(hDelP,
			WM_SETTEXT,
			NULL,
			(LPARAM)"Prenume");
		// Create a push button
		HWND hWndButton = CreateWindowEx(NULL,
			"BUTTON",
			"Sterge Client",
			WS_TABSTOP | WS_VISIBLE |
			WS_CHILD | BS_DEFPUSHBUTTON,
			60,
			65,
			100,
			24,
			hwnd,
			(HMENU)ADD_BUTTON2,
			GetModuleHandle(NULL),
			NULL);
		SendMessage(hWndButton,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
	}
	break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
LRESULT CALLBACK windowprocessforwindow5(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	if (GetFocus() == hSrcN && nume5 == false)
	{
		SendMessage(hSrcN,
			WM_SETTEXT,
			NULL,
			(LPARAM)"");
		nume5 = true;
	}
	if (GetFocus() == hSrcP && prenume5 == false)
	{
		SendMessage(hSrcP,
			WM_SETTEXT,
			NULL,
			(LPARAM)"");
		prenume5 = true;
	}
	if (GetFocus() == hSrcC && carte5 == false)
	{
		SendMessage(hSrcC,
			WM_SETTEXT,
			NULL,
			(LPARAM)"");
		carte5 = true;
	}
	switch (message) {
	case WM_DESTROY:
	{
		window5open = false;
		nume5 = false;
		prenume5 = false;
		carte5 = false;
	}
		break;
	case WM_CREATE:
	{
		// Create an edit box
		hSrcN = CreateWindowEx(WS_EX_CLIENTEDGE,
			"EDIT",
			"",
			WS_CHILD | WS_VISIBLE |
			ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
			2,
			7,
			230,
			20,
			hwnd,
			(HMENU)ADD_EDITN5,
			GetModuleHandle(NULL),
			NULL);
		HGDIOBJ hfDefault = GetStockObject(DEFAULT_GUI_FONT);
		SendMessage(hSrcN,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
		SendMessage(hSrcN,
			WM_SETTEXT,
			NULL,
			(LPARAM)"Nume");
		hSrcP = CreateWindowEx(WS_EX_CLIENTEDGE,
			"EDIT",
			"",
			WS_CHILD | WS_VISIBLE |
			ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
			2,
			34,
			230,
			20,
			hwnd,
			(HMENU)ADD_EDITP5,
			GetModuleHandle(NULL),
			NULL);
		hfDefault = GetStockObject(DEFAULT_GUI_FONT);
		SendMessage(hSrcP,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
		SendMessage(hSrcP,
			WM_SETTEXT,
			NULL,
			(LPARAM)"Prenume");
		hSrcC = CreateWindowEx(WS_EX_CLIENTEDGE,
			"EDIT",
			"",
			WS_CHILD | WS_VISIBLE |
			ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
			240,
			34,
			230,
			20,
			hwnd,
			(HMENU)ADD_EDITC5,
			GetModuleHandle(NULL),
			NULL);
		hfDefault = GetStockObject(DEFAULT_GUI_FONT);
		SendMessage(hSrcC,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
		SendMessage(hSrcC,
			WM_SETTEXT,
			NULL,
			(LPARAM)"Carte");
		// Create a push button
		HWND hWndButton = CreateWindowEx(NULL,
			"BUTTON",
			"Cautare Client",
			WS_TABSTOP | WS_VISIBLE |
			WS_CHILD | BS_DEFPUSHBUTTON,
			60,
			65,
			100,
			24,
			hwnd,
			(HMENU)ADD_BUTTON2,
			GetModuleHandle(NULL),
			NULL);
		SendMessage(hWndButton,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
		HWND hWndButton2 = CreateWindowEx(NULL,
			"BUTTON",
			"Cautare Carte",
			WS_TABSTOP | WS_VISIBLE |
			WS_CHILD | BS_DEFPUSHBUTTON,
			300,
			65,
			100,
			24,
			hwnd,
			(HMENU)ADD_BUTTON2,
			GetModuleHandle(NULL),
			NULL);
		SendMessage(hWndButton2,
			WM_SETFONT,
			(WPARAM)hfDefault,
			MAKELPARAM(FALSE, 0));
	}
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
