#define UNICODE

//Header Files
#include <windows.h>

//Macro Definition
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

//Gloabal Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
DWORD WINAPI ThreadProcOne(LPVOID);
DWORD WINAPI ThreadProcTwo(LPVOID);

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Variable Declaration
	WNDCLASSEX wndclassex;
	HWND hwnd;
	MSG message;
	TCHAR szAppName[] = TEXT("FirstWindow");

	//Code
	//WNDCLASSEX Initialization
	wndclassex.cbSize = sizeof(WNDCLASSEX);
	wndclassex.style = CS_HREDRAW | CS_VREDRAW;
	wndclassex.cbClsExtra = 0;
	wndclassex.cbWndExtra = 0;
	wndclassex.lpfnWndProc = WndProc;
	wndclassex.hInstance = hInstance;
	wndclassex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclassex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclassex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclassex.lpszClassName = szAppName;
	wndclassex.lpszMenuName = NULL;
	wndclassex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//Register WNDCLASSEX
	RegisterClassEx(&wndclassex);

	//Create Window
	hwnd = CreateWindow(szAppName,
		TEXT("Omkar Phale"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	//Show Window
	ShowWindow(hwnd, iCmdShow);

	//Update Window
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
	static HANDLE hThreadOne = NULL;
	static HANDLE hThreadTwo = NULL;

	//Code
	switch (iMessage)
	{
		//First Message To Be Received
		case WM_CREATE:
			hThreadOne = CreateThread(NULL,
				0,
				(LPTHREAD_START_ROUTINE)ThreadProcOne,
				(LPVOID)hwnd,
				0,
				NULL);

			hThreadTwo = CreateThread(NULL,
				0,
				(LPTHREAD_START_ROUTINE)ThreadProcTwo,
				(LPVOID)hwnd,
				0,
				NULL);
			break;

		case WM_LBUTTONDOWN:
			MessageBox(hwnd,
				TEXT("This is a multithreading application..."),
				TEXT("Message::WM_LBUTTONDOWN"),
				MB_OK);
			break;

		//Last Message To Be Received
		case WM_DESTROY:
			if (hThreadOne)
			{
				CloseHandle(hThreadOne);
				hThreadOne = NULL;
			}

			if (hThreadTwo)
			{
				CloseHandle(hThreadTwo);
				hThreadTwo = NULL;
			}

			PostQuitMessage(0);
			break;
	}

	return(DefWindowProc(hwnd, iMessage, wParam, lParam));
}

DWORD WINAPI ThreadProcOne(LPVOID lpvParam)
{
	//Local Variable Declaration
	HDC hdc;
	ULONG lCounter;
	TCHAR szPrintable[255];
	RECT rect;

	//Code
	GetWindowRect(GetDesktopWindow(), &rect);

	hdc = GetDC((HWND)lpvParam);
	for (lCounter = 0; lCounter < ULONG_MAX; lCounter++)
	{
		wsprintf(szPrintable, TEXT("ThreadOne[Increasing]::%lu"), lCounter);
		TextOut(hdc, 
			(rect.right - WINDOW_WIDTH),
			WINDOW_HEIGHT / 2, 
			szPrintable, 
			wcslen(szPrintable));
		SetTextColor(hdc, RGB(0, 255, 0));
	}

	if (hdc)
	{
		ReleaseDC((HWND)lpvParam, hdc);
		hdc = NULL;
	}

	return(0);
}

DWORD WINAPI ThreadProcTwo(LPVOID lpvParam)
{
	//Local Variable Declaration
	HDC hdc;
	ULONG lCounter;
	TCHAR szPrintable[255];
	RECT rect;

	//Code
	GetWindowRect(GetDesktopWindow(), &rect);

	hdc = GetDC((HWND)lpvParam);
	for (lCounter = ULONG_MAX; lCounter >= 0; lCounter--)
	{
		wsprintf(szPrintable, TEXT("ThreadTwo[Decreasing]::%lu"), lCounter);
		TextOut(hdc, 
			WINDOW_WIDTH / 2,
			WINDOW_HEIGHT / 2, 
			szPrintable, 
			wcslen(szPrintable));
		SetTextColor(hdc, RGB(255, 0, 0));
	}

	if (hdc)
	{
		ReleaseDC((HWND)lpvParam, hdc);
		hdc = NULL;
	}

	return(0);
}
