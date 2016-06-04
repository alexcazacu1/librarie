#include <windows.h>
#include<CommCtrl.h>
#define ADD_BUTTON	101	// Button identifier
#define EDIT_BUTTON	102
#define DEL_BUTTON	103
#define SRC_BUTTON	104
#define IDC_MAIN_LIST  105			// Edit box identifier
HWND hEdit;

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nShowCmd)
{
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
		WS_OVERLAPPEDWINDOW,
		500,
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
	ZeroMemory(&msg, sizeof(MSG));

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
	{
		// Create an edit box
		hEdit = CreateWindowEx(WS_EX_CLIENTEDGE,
			"LISTBOX",
			"",
			WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
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
			"Introdu un client",
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
			"Editeaza un client",
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
		case ADD_BUTTON:
		{
			char buffer[256];
			SendMessage(hEdit,
				WM_GETTEXT,
				sizeof(buffer) / sizeof(buffer[0]),
				reinterpret_cast<LPARAM>(buffer));
			MessageBox(NULL,
				buffer,
				"Information",
				MB_ICONINFORMATION);
		}
		break;
		case DEL_BUTTON:
		{

		}
		break;
		case EDIT_BUTTON:
		{

		}
		break;
		case SRC_BUTTON:
		{

		}
		break;
		}
		break;

	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}