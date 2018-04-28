// CClient_LB3.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "CClient_LB3.h"

#define MAX_LOADSTRING 100
#define ITERATIONS 500000

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND g_hEditX;
HWND g_hEditY;
HWND g_hEditResult;

HWND g_hEditTime1;
HWND g_hEditTime2;
HWND g_hEditTime3;

HWND g_hButtonLate;
HWND g_hButtonID;
HWND g_hButtonVtbl;



typedef void(*LPFN_ADD)(double, double, double*);
LPFN_ADD ADD;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
VOID				ShowResult(HWND,int);

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
    LoadStringW(hInstance, IDC_CCLIENTLB3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CCLIENTLB3));

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

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CCLIENTLB3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CCLIENTLB3);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

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

		g_hEditX = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT("0"),
			WS_CHILD | WS_VISIBLE ,
			40, 40, 100, 20, hWnd, (HMENU)IDC_EDIT_X, GetModuleHandle(NULL), NULL);
		if (g_hEditX == NULL)
			MessageBox(hWnd, TEXT("Could not create edit box."), TEXT("Error"), MB_OK | MB_ICONERROR);

		g_hEditY = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT("0"),
			WS_CHILD | WS_VISIBLE,
			180, 40, 100, 20, hWnd, (HMENU)IDC_EDIT_Y, GetModuleHandle(NULL), NULL);
		if (g_hEditY == NULL)
			MessageBox(hWnd, TEXT("Could not create edit box."), TEXT("Error"), MB_OK | MB_ICONERROR);

		g_hEditResult = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT("0"),
			WS_CHILD | WS_VISIBLE,
			320, 40, 100, 20, hWnd, (HMENU)IDC_EDIT_RES, GetModuleHandle(NULL), NULL);
		if (g_hEditResult == NULL)
			MessageBox(hWnd, TEXT("Could not create edit box."), TEXT("Error"), MB_OK | MB_ICONERROR);

		g_hEditTime1 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT("0"),
			WS_CHILD | WS_VISIBLE,
			40, 120, 100, 20, hWnd, (HMENU)IDC_EDIT_TIME_1, GetModuleHandle(NULL), NULL);
		if (g_hEditTime1 == NULL)
			MessageBox(hWnd, TEXT("Could not create edit box."), TEXT("Error"), MB_OK | MB_ICONERROR);

		g_hEditTime2 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT("0"),
			WS_CHILD | WS_VISIBLE,
			180, 120, 100, 20, hWnd, (HMENU)IDC_EDIT_TIME_2, GetModuleHandle(NULL), NULL);
		if (g_hEditTime2 == NULL)
			MessageBox(hWnd, TEXT("Could not create edit box."), TEXT("Error"), MB_OK | MB_ICONERROR);

		g_hEditTime3 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT("0"),
			WS_CHILD | WS_VISIBLE,
			320, 120, 100, 20, hWnd, (HMENU)IDC_EDIT_TIME_3, GetModuleHandle(NULL), NULL);
		if (g_hEditTime3 == NULL)
			MessageBox(hWnd, TEXT("Could not create edit box."), TEXT("Error"), MB_OK | MB_ICONERROR);



		g_hButtonLate = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("Late"),
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			40, 200, 100, 23, hWnd, (HMENU)IDC_BUTTON_LATE, GetModuleHandle(NULL), NULL);
		if (g_hButtonLate == NULL)
			MessageBox(hWnd, TEXT("Could not create edit box."), TEXT("Error"), MB_OK | MB_ICONERROR);


		g_hButtonID = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("ID"),
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			180, 200, 100, 20, hWnd, (HMENU)IDC_BUTTON_ID, GetModuleHandle(NULL), NULL);
		if (g_hButtonID == NULL)
			MessageBox(hWnd, TEXT("Could not create edit box."), TEXT("Error"), MB_OK | MB_ICONERROR);


		g_hButtonVtbl = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("Vtbl"),
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			320, 200, 100, 20, hWnd,(HMENU)IDC_BUTTON_VTBL, GetModuleHandle(NULL), NULL);
		if (g_hButtonVtbl == NULL)
			MessageBox(hWnd, TEXT("Could not create edit box."), TEXT("Error"), MB_OK | MB_ICONERROR);


	}
	break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			case IDC_BUTTON_LATE:
			{

				ShowResult(hWnd,IDC_EDIT_TIME_1);

				//MessageBox(hWnd, TEXT("IDC_BUTTON_LATE"), TEXT("Сообщение"), MB_OK);
			}
			break;
			case IDC_BUTTON_ID:
			{
				ShowResult(hWnd,IDC_EDIT_TIME_2);
				//MessageBox(hWnd, TEXT("IDC_BUTTON_ID"), TEXT("Сообщение"), MB_OK);
			}
			break;
			case IDC_BUTTON_VTBL:
			{
				ShowResult(hWnd,IDC_EDIT_TIME_3);
				
				//MessageBox(hWnd, TEXT("IDC_BUTTON_VTBL"), TEXT("Сообщение"), MB_OK);
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
        PostQuitMessage(0);
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


void ShowResult(HWND hWnd,int ID)
{
	HINSTANCE hLib = LoadLibrary(TEXT("../DEBUG/ATL_PR_1.dll"));
	if (hLib == NULL)
	{
		MessageBox(NULL, TEXT("Ошибка загрузки библиотеки"), NULL, MB_OK);
	}
	else
	{
		ADD = (LPFN_ADD)GetProcAddress(hLib, "Add");


		int bufSize = 1024;
		TCHAR szTextX[1024];
		GetDlgItemText(hWnd, IDC_EDIT_X, szTextX, bufSize);

		TCHAR szTextY[1024];
		GetDlgItemText(hWnd, IDC_EDIT_Y, szTextY, bufSize);

		DWORD Start = GetTickCount();
		double Delta = 0.0f;
		double result = NULL;

		ADD(_tstol(szTextX),_tstol(szTextY),&result);

		for (int i = 0; i < ITERATIONS; i++)
		{
			ADD(_tstoi(szTextX), _tstoi(szTextY), &result);
		}

		Delta = (GetTickCount() - Start) / 1000.0f;

		TCHAR szResult[1024];
		wsprintf(szResult, TEXT("%d"), result);
		SetDlgItemText(hWnd, IDC_EDIT_RES, szResult);

		TCHAR szTime1[1024];
		swprintf_s(szTime1, TEXT("%f"), Delta);
		SetDlgItemText(hWnd, ID, szTime1);
		
		
		if (!ADD)
		{// handle the error
			FreeLibrary(hLib);
			MessageBox(NULL, TEXT("Ошибка загрузки функции/переменной из библиотеки"), NULL, MB_OK);
		}
	}
}
