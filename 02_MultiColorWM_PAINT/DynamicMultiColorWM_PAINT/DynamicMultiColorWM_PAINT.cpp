//Header Files
#include <windows.h>

//Gloabal Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Macro Definition
#define UD_TIMER 4896

//Global Variable Declaration
char cPaintColorFlag = 'w';
int iPaintFlag;

//enum Declaration
enum ColorChoices
{
	CC_VOILET,
	CC_INDIGO,
	CC_BLUE,
	CC_GREEN,
	CC_YELLOW,
	CC_ORANGE,
	CC_RED,
	CC_DEFAULT
};

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
	//Local Variable Declaration
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	TCHAR szMessage[] = TEXT("Namaskar Window!");
	TCHAR szColorChoices[255];

	//Code
	switch (iMessage)
	{
		case WM_CREATE:
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
			SetBkColor(hdc, RGB(0, 0, 0));	

			switch(iPaintFlag)
			{
				case CC_VOILET:
					SetTextColor(hdc, RGB(148, 0, 211));
					break;

				case CC_INDIGO:
					SetTextColor(hdc, RGB(75, 0, 130));
					break;

				case CC_BLUE:
					SetTextColor(hdc, RGB(0, 0, 255));
					break;

				case CC_GREEN:
					SetTextColor(hdc, RGB(0, 255, 0));
					break;
				
				case CC_YELLOW:
					SetTextColor(hdc, RGB(255, 255, 0));
					break;

				case CC_ORANGE:
					SetTextColor(hdc, RGB(255, 127, 0));
					break;

				case CC_RED:
					SetTextColor(hdc, RGB(255, 0, 0));
					break;

				default:
					SetTextColor(hdc, RGB(255, 255, 255));
					break;
			}

			DrawText(hdc, szMessage, -1, &rc, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			EndPaint(hwnd, &ps);
			break;

		//Last Message To Be Received
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}

	return(DefWindowProc(hwnd, iMessage, wParam, lParam));
}