#define UNICODE

//Header Files
#include <windows.h>
#include <process.h>

//Gloabal Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void __cdecl ThreadProcOne(void*);
void __cdecl ThreadProcTwo(void*);

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
	unsigned long ulThreadOne = 0;
	unsigned long ulThreadTwo = 0;

	//Code
	switch (iMessage)
	{
		//First Message To Be Received
		case WM_CREATE:
			ulThreadOne = _beginthread(ThreadProcOne, 0, (void*)hwnd);
			
			ulThreadTwo = _beginthread(ThreadProcTwo, 0, (void*)hwnd);

			break;

		case WM_LBUTTONDOWN:
			MessageBox(hwnd,
				TEXT("This is a multithreading application..."),
				TEXT("Message::WM_LBUTTONDOWN"),
				MB_OK);
			break;

		//Last Message To Be Received
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}

	return(DefWindowProc(hwnd, iMessage, wParam, lParam));
}

void __cdecl ThreadProcOne(void* vpParam)
{
	//Local Variable Declaration
	HDC hdc;
	ULONG lCounter;
	TCHAR szPrintable[255];

	//Code
	hdc = GetDC((HWND)vpParam);
	for (lCounter = 0; lCounter < ULONG_MAX; lCounter++)
	{
		wsprintf(szPrintable, TEXT("ThreadOne[Increasing]::%lu"), lCounter);
		TextOut(hdc, 5, 5, szPrintable, wcslen(szPrintable));
		SetTextColor(hdc, RGB(255, 0, 0));
	}

	if (hdc)
	{
		ReleaseDC((HWND)vpParam, hdc);
		hdc = NULL;
	}

	_endthread();
}

void __cdecl ThreadProcTwo(void* vpParam)
{
	//Local Variable Declaration
	HDC hdc;
	ULONG lCounter;
	TCHAR szPrintable[255];

	//Code
	hdc = GetDC((HWND)vpParam);
	for (lCounter = ULONG_MAX; lCounter >= 0; lCounter--)
	{
		wsprintf(szPrintable, TEXT("ThreadTwo[Decreasing]::%lu"), lCounter);
		TextOut(hdc, 5, 20, szPrintable, wcslen(szPrintable));
		SetTextColor(hdc, RGB(0, 255, 0));
	}

	if (hdc)
	{
		ReleaseDC((HWND)vpParam, hdc);
		hdc = NULL;
	}

	_endthread();
}
