//Header File Declaration
#include "DynamiceColorChange.h"
#include <windows.h>

//Global Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Macro Definitions
#define UD_TIMER 4896

//Global Varible Declaration
int iPaintFlag = 0;

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Variable Declarations
	WNDCLASSEX wndclassex;
	HWND hwnd;
	MSG message;
	TCHAR szAppName[] = TEXT("FirstWindowUsingWin32");

	//Code
	//Initialization Of WNDCLASSEX
	wndclassex.cbSize = sizeof(WNDCLASSEX);
	wndclassex.style = CS_HREDRAW | CS_VREDRAW;
	wndclassex.cbClsExtra = 0;
	wndclassex.cbWndExtra = 0;
	wndclassex.lpfnWndProc = WndProc;
	wndclassex.hInstance = hInstance;
	wndclassex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(DEFAULT_LARGE_ICON));
	wndclassex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclassex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclassex.lpszClassName = szAppName;
	wndclassex.lpszMenuName = NULL;
	wndclassex.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(DEFAULT_LARGE_ICON));

	//Register Above Class
	RegisterClassEx(&wndclassex);

	//Create Window
	hwnd = CreateWindow(szAppName,
		TEXT("Omkar Phale RTR2020-112"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	//Show And Update Window
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//Message Loop
	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return((int)message.wParam);
}

//Global Function Definition
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//Local Variable Declaration
	HDC hdc; 
	static HBRUSH hBrush[8];
	PAINTSTRUCT ps;
	RECT rc;

	//Code
	switch (iMessage)
	{
		case WM_CREATE:
			hBrush[0] = CreateSolidBrush(RGB(255, 0, 0));
			hBrush[1] = CreateSolidBrush(RGB(0, 255, 0));
			hBrush[2] = CreateSolidBrush(RGB(0, 0, 255));
			hBrush[3] = CreateSolidBrush(RGB(255, 0, 0));
			hBrush[4] = CreateSolidBrush(RGB(0, 255, 255));
			hBrush[5] = CreateSolidBrush(RGB(255, 0, 255));
			hBrush[6] = CreateSolidBrush(RGB(255, 255, 255));
			hBrush[7] = CreateSolidBrush(RGB(0, 0, 0));

			SetTimer(hwnd, UD_TIMER, 1000, NULL);
			break;

		case WM_TIMER:
			KillTimer(hwnd, UD_TIMER);
			iPaintFlag++;

			if (iPaintFlag > 7)
			{
				iPaintFlag = 0;
			}

			InvalidateRect(hwnd, NULL, TRUE);
			SetTimer(hwnd, UD_TIMER, 1000, NULL);
			break;

		case WM_PAINT:
			GetClientRect(hwnd, &rc);
			hdc = BeginPaint(hwnd, &ps);
			SelectObject(hdc, hBrush[iPaintFlag]);
			FillRect(hdc, &rc, hBrush[iPaintFlag]);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}

	return(DefWindowProc(hwnd, iMessage, wParam, lParam));
}
