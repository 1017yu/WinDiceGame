#include <windows.h>
//#include "resource.h"
#include <iostream>

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK about(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
HBITMAP hBmpJ1, hBmpJ2, hBmpJ3, hBmpJ4, hBmpJ5, hBmpJ6;
HBITMAP hBmpJ11, hBmpJ22, hBmpJ33, hBmpJ44, hBmpJ55, hBmpJ66;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstanc, LPSTR lpCmdLine, int nShowCmd)

{
	char szTitle[] = "My First Dice Game";
	char szClass[] = "Class";

	// 1. Declare window class -----------------------------------------------------

	WNDCLASSEX WndEx;
	WndEx.style = NULL; // window style
	WndEx.lpfnWndProc = WndProc; //window procedure(function) pointer
	WndEx.cbClsExtra = 0; //additional memory size for widow class
	WndEx.cbWndExtra = 0; // additional memory size for window
	WndEx.hInstance = hInstance; // intance handle of the window procdeure
	WndEx.hIcon = LoadIcon(NULL, ""); //big icon
	WndEx.hIconSm = LoadIcon(hInstance, ""); //small icon
	WndEx.hCursor = LoadCursor(NULL, IDC_ARROW);//cursor
	WndEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//background
	WndEx.lpszMenuName = "IDR_MENU";//menui
	WndEx.lpszClassName = szClass;//window class name
	WndEx.cbSize = sizeof(WndEx); //size of window class structure

	// 2. Register window calss -----------------------------------------------------

	RegisterClassEx(&WndEx);

	// 3. Create window -------------------------------------------------------------
	HWND hWnd;
	hWnd = CreateWindowEx(NULL, szClass, szTitle,
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		320 * 2, 240 * 2, NULL, NULL, hInstance, NULL);

	// 4. Show and Update window-----------------------------------------------------

	ShowWindow(hWnd, nShowCmd);
	UpdateWindow(hWnd);

	hBmpJ1 = LoadBitmap(hInstance, "IDB_J1");
	hBmpJ2 = LoadBitmap(hInstance, "IDB_J2");
	hBmpJ3 = LoadBitmap(hInstance, "IDB_J3");
	hBmpJ4 = LoadBitmap(hInstance, "IDB_J4");
	hBmpJ5 = LoadBitmap(hInstance, "IDB_J5");
	hBmpJ6 = LoadBitmap(hInstance, "IDB_J6");
	hBmpJ11 = LoadBitmap(hInstance, "IDB_J1");
	hBmpJ22 = LoadBitmap(hInstance, "IDB_J2");
	hBmpJ33 = LoadBitmap(hInstance, "IDB_J3");
	hBmpJ44 = LoadBitmap(hInstance, "IDB_J4");
	hBmpJ55 = LoadBitmap(hInstance, "IDB_J5");
	hBmpJ66 = LoadBitmap(hInstance, "IDB_J6");


	// 5. Message loop --------------------------------------------------------------

	MSG mSg;
	while (TRUE)
	{
		if (PeekMessage(&mSg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (!GetMessage(&mSg, NULL, 0, 0))
				break;
			TranslateMessage(&mSg);
			DispatchMessage(&mSg);
		}
	}
	return mSg.wParam;
}

HINSTANCE hInst;
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hButtStart, hButtStop, hButtExit;
	static HWND hEdit;
	static int a, b, ma, mb;

	char szText[100];

	HDC hDC, hMemDC, hMemDC2;

	switch (uMsg)
	{
	case WM_CREATE:
		hButtStart = CreateWindow("BUTTON", "Start", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			310, 400, 90, 30, hWnd, (HMENU)1, NULL, NULL);

		hButtStop = CreateWindow("BUTTON", "Stop", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			410, 400, 90, 30, hWnd, (HMENU)2, NULL, NULL);

		hButtExit = CreateWindow("BUTTON", "Exit", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			510, 400, 90, 30, hWnd, (HMENU)3, NULL, NULL);

		return FALSE;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case 1:
			SetTimer(hWnd, 1, 100, NULL);
			break;

		case 2:
			hDC = GetDC(hWnd);
			sprintf_s(szText, "Dice Score: %d + %d = %d ", ma, mb, ma + mb);
			TextOut(hDC, 10, 410, szText, lstrlen(szText));
			KillTimer(hWnd, 1);
			break;

		case 3:
			PostQuitMessage(0);
			break;
		}

		return FALSE;

	case WM_TIMER:
		hDC = GetDC(hWnd);
		hMemDC = CreateCompatibleDC(hDC);
		hMemDC2 = CreateCompatibleDC(hDC);
		InvalidateRect(hWnd, NULL, TRUE);
		UpdateWindow(hWnd);
		a = rand();
		b = rand();

		ma = (a % 6) + 1;  /* ma = 0+1 ~ 5+1 */
		mb = (b % 6) + 1;
		switch (ma) {
		case 1:
			SelectObject(hMemDC, hBmpJ1);
			
			break;

		case 2:
			SelectObject(hMemDC, hBmpJ2);
			
			break;

		case 3:
			SelectObject(hMemDC, hBmpJ3);
		
			break;

		case 4:
			SelectObject(hMemDC, hBmpJ4);
		
			break;

		case 5:
			SelectObject(hMemDC, hBmpJ5);
	
			break;

		case 6:
			SelectObject(hMemDC, hBmpJ6);

			break;
		}

		BitBlt(hDC, (ma-1)*100, (mb-1)*60, 88, 88, hMemDC, 0, 0, SRCCOPY);

		switch (mb) {
		case 1:
			SelectObject(hMemDC, hBmpJ1);

			break;

		case 2:
			SelectObject(hMemDC, hBmpJ2);

			break;

		case 3:
			SelectObject(hMemDC, hBmpJ3);

			break;

		case 4:
			SelectObject(hMemDC, hBmpJ4);

			break;

		case 5:
			SelectObject(hMemDC, hBmpJ5);

			break;

		case 6:
			SelectObject(hMemDC, hBmpJ6);

			break;
		}

		BitBlt(hDC, (mb - 1) * 100, (ma - 1) * 60, 88, 88, hMemDC, 0, 0, SRCCOPY);
		ReleaseDC(hWnd, hDC);
		DeleteDC(hMemDC);

		return FALSE;

	case WM_DESTROY:
		PostQuitMessage(0);

		return FALSE;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}