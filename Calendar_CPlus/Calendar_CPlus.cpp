// Calendar_CPlus.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Calendar_CPlus.h"
#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND g_hEditDay;
HWND g_hEditMonth;

HWND g_hButtonSet;
HWND g_hButtonGet;


IDispatch* g_pIDispatch;
TCHAR g_day[10];
TCHAR g_month[10];
TCHAR g_year[10];

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
VOID				GetDate_Month(HWND);
VOID				SetDate_Month(TCHAR*, short);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_CALENDARCPLUS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CALENDARCPLUS));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CALENDARCPLUS));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_CALENDARCPLUS);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 450, 330, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		// Инициализировать библиотеку OLE. 
		HRESULT hr = OleInitialize(NULL);
		// Получить CLSID приложения. 
		wchar_t progid[] = L"MSCAL.Календарь.7";
		CLSID clsid;
		hr = ::CLSIDFromProgID(progid, &clsid);
		// Создать компонент. 
		hr = ::CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER, IID_IDispatch, (void**)&g_pIDispatch);

		CreateWindowEx(NULL, TEXT("STATIC"), TEXT("День"),
			WS_CHILD | WS_VISIBLE,
			40, 20, 100, 20, hWnd, (HMENU)IDC_STATIC_DAY, GetModuleHandle(NULL), NULL);

		CreateWindowEx(NULL, TEXT("STATIC"), TEXT("Месяц"),
			WS_CHILD | WS_VISIBLE,
			180, 20, 100, 20, hWnd, (HMENU)IDC_STATIC_DAY, GetModuleHandle(NULL), NULL);

		g_hEditDay = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT("0"),
			WS_CHILD | WS_VISIBLE,
			40, 40, 100, 20, hWnd, (HMENU)IDC_EDIT_DAY, GetModuleHandle(NULL), NULL);
		if (g_hEditDay == NULL)
			MessageBox(hWnd, TEXT("Could not create edit box."), TEXT("Error"), MB_OK | MB_ICONERROR);

		g_hEditMonth = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT("0"),
			WS_CHILD | WS_VISIBLE,
			180, 40, 100, 20, hWnd, (HMENU)IDC_EDIT_MONTH, GetModuleHandle(NULL), NULL);
		if (g_hEditMonth == NULL)
			MessageBox(hWnd, TEXT("Could not create edit box."), TEXT("Error"), MB_OK | MB_ICONERROR);

		g_hButtonSet = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("Задать"),
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			40, 200, 100, 23, hWnd, (HMENU)IDC_BUTTON_SET, GetModuleHandle(NULL), NULL);
		if (g_hButtonSet == NULL)
			MessageBox(hWnd, TEXT("Could not create edit box."), TEXT("Error"), MB_OK | MB_ICONERROR);

		g_hButtonGet = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("Получить"),
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			40, 240, 100, 23, hWnd, (HMENU)IDC_BUTTON_GET, GetModuleHandle(NULL), NULL);
		if (g_hButtonGet == NULL)
			MessageBox(hWnd, TEXT("Could not create edit box."), TEXT("Error"), MB_OK | MB_ICONERROR);

		GetDate_Month(hWnd);
		SetDlgItemText(hWnd, IDC_EDIT_DAY, g_day);
		SetDlgItemText(hWnd, IDC_EDIT_MONTH, g_month);

	}
	break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDC_BUTTON_SET:
		{
			TCHAR day[10];
			TCHAR month[10];

			GetDlgItemText(hWnd, IDC_EDIT_DAY, day, 255);
			GetDlgItemText(hWnd, IDC_EDIT_MONTH, month, 255);


			short dayS = _ttoi(day);
			short monthS = _ttoi(month);

			TCHAR dayname[] = L"Day";

			SetDate_Month(dayname, dayS);

			TCHAR monthname[] = L"Month";

			SetDate_Month(monthname, monthS);
		}
		break;
		case IDC_BUTTON_GET:
		{
			GetDate_Month(hWnd);

			TCHAR datenew[100];

			wsprintf(datenew, TEXT("Установленная дата: %s.%s.%s"), g_day, g_month, g_year);

			MessageBox(hWnd, datenew, TEXT("Сообщение"), MB_OK);
		}
		break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
	{
		OleUninitialize();
		PostQuitMessage(0);
	}
	break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}


void GetDate_Month(HWND hWnd)
{

	DISPID dispid;
	TCHAR name1[] = L"Value";

	OLECHAR* name = name1;
	g_pIDispatch->GetIDsOfNames(
		IID_NULL,   // Должно быть IID_NULL
		&name,    // Имя функции
		1,    // Число имен
		GetUserDefaultLCID(), // Информация локализации
		&dispid);   // Диспетчерский идентификатор 


	VARIANT vResult;
	::VariantInit(&vResult);

	DISPPARAMS dispparamsNoArgs = { NULL,NULL,0,0 };

	g_pIDispatch->Invoke(
		dispid,
		IID_NULL,
		GetUserDefaultLCID(),
		DISPATCH_PROPERTYGET,
		&dispparamsNoArgs,
		&vResult,
		NULL,
		NULL);

	SYSTEMTIME date;
	ZeroMemory(&date, sizeof(SYSTEMTIME));

	::VariantTimeToSystemTime(vResult.date, &date);

	wsprintf(g_day,TEXT("%d"),date.wDay);
	wsprintf(g_month, TEXT("%d"), date.wMonth);
	wsprintf(g_year, TEXT("%d"), date.wYear);

}


void SetDate_Month(TCHAR* name, short value)
{

	DISPID dispid;
	DISPID dispPutID = DISPID_PROPERTYPUT;

	OLECHAR* NameOle = reinterpret_cast<OLECHAR*>(name);


	g_pIDispatch->GetIDsOfNames(
		IID_NULL,   // Должно быть IID_NULL
		&NameOle,    // Имя функции
		1,    // Число имен
		GetUserDefaultLCID(), // Информация локализации
		&dispid);   // Диспетчерский идентификатор 


	VARIANTARG arg;

	::VariantInit(&arg);
	arg.vt = VT_I2;
	arg.iVal = value;

	DISPPARAMS dispparams = { &arg,&dispPutID,1,1 };

	g_pIDispatch->Invoke(
		dispid,
		IID_NULL,
		GetUserDefaultLCID(),
		DISPATCH_PROPERTYPUT,
		&dispparams,
		NULL,
		NULL,
		NULL);
}

