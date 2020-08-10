//Headers
#include <windows.h>
#include "08_MyMath.h"

//Global Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Pragma Declaration
#pragma comment(lib, "08_MyMath.lib")

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
	wndclassex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclassex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclassex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclassex.lpszClassName = szAppName;
	wndclassex.lpszMenuName = NULL;
	wndclassex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

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
	int iNumber = 5;
	int iResult;
	TCHAR szResult[255];

	//Code
	switch (iMessage)
	{
	case WM_CREATE:
		iResult = MakeSquare(iNumber);
		wsprintf(szResult, TEXT("Square of %d is %d"), iNumber, iResult);

		MessageBox(hwnd,
			szResult,
			TEXT("Square Result"),
			MB_OK);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd, iMessage, wParam, lParam));
}
