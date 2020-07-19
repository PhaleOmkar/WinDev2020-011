//Header File Declaration
#include "EnumWindowImplementation.h"
#include <iostream>
#include <windows.h>
using namespace std;

//Global Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);

//Global Variable Declaration
HWND hwndEW;
FILE* gpFile;

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Variable Declarations
	WNDCLASSEX wndclassex;
	HWND hwnd;
	MSG message;
	TCHAR szAppName[] = TEXT("FirstWindowUsingWin32");

	//Error Checking Of 'fopen_s()'
	if (fopen_s(&gpFile, "CodeLog.txt", "w") != 0)
	{
		MessageBox(NULL,
			TEXT("Cannot open desire file"),
			TEXT("Message::fopen_s() failed"),
			MB_ICONERROR);
		exit(0);
	}

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

	EnumWindows(EnumWindowsProc, NULL);

	//Message Loop
	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	if (gpFile)
	{
		fclose(gpFile);
		gpFile = NULL;
	}
	return((int)message.wParam);
}

//Global Function Definition
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//Code
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd, iMessage, wParam, lParam));
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	char class_name[80];
	char title[80];

	GetClassName(hwnd, class_name, sizeof(class_name));
	GetWindowText(hwnd, title, sizeof(title));

	fprintf(gpFile, "Class Name : %s\n", class_name);
	fprintf(gpFile, "Title : %s\n", title);

	fprintf(gpFile, "\n");
	
	return TRUE;
}
