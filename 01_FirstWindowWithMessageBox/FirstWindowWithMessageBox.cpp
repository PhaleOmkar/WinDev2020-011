//Header Files
#include <windows.h>

//Gloabal Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

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
	wndclassex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
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
	//Code
	switch (iMessage)
	{
		//First Message To Be Received
		case WM_CREATE :
			MessageBox(hwnd,
				TEXT("WM_CREATE received..."),
				TEXT("Message::WM_CREATE"),
				MB_OK);
				break;

		case WM_LBUTTONDOWN:
			MessageBox(hwnd,
				TEXT("WM_LBUTTONDOWN received..."),
				TEXT("Message::WM_LBUTTONDOWN"),
				MB_OK);
			break;

		case WM_RBUTTONDOWN:
			MessageBox(hwnd,
				TEXT("WM_RBUTTONDOWN received..."),
				TEXT("Message::WM_RBUTTONDOWN"),
				MB_OK);
			break;

		case WM_KEYDOWN:
			MessageBox(hwnd,
				TEXT("WM_KEYDOWN received..."),
				TEXT("Message::WM_KEYDOWN"),
				MB_OK);
			break;

		//Last Message To Be Received
		case WM_DESTROY:
			MessageBox(hwnd,
				TEXT("WM_DESTROY received..."),
				TEXT("Message::WM_DESTROY"),
				MB_OK);
			
			PostQuitMessage(0);
			break;
	}

	return(DefWindowProc(hwnd, iMessage, wParam, lParam));
}