//Header Files
#include <windows.h>

//Gloabal Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Global Variable Declaration
char cPaintColorFlag = 'w';

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
		case WM_CHAR:
			switch (wParam)
			{
				case 'v':
				case 'V':
					cPaintColorFlag = 'v';
					InvalidateRect(hwnd, NULL, TRUE);
					break;
				
				case 'i':
				case 'I':
					cPaintColorFlag = 'i';
					InvalidateRect(hwnd, NULL, TRUE);
					break;

				case 'b':
				case 'B':
					cPaintColorFlag = 'b';
					InvalidateRect(hwnd, NULL, TRUE);
					break;

				case 'g':
				case 'G':
					cPaintColorFlag = 'g';
					InvalidateRect(hwnd, NULL, TRUE);
					break;

				case 'y':
				case 'Y':
					cPaintColorFlag = 'y';
					InvalidateRect(hwnd, NULL, TRUE);
					break;

				case 'o':
				case 'O':
					cPaintColorFlag = 'o';
					InvalidateRect(hwnd, NULL, TRUE);
					break;
					break;

				case 'r':
				case 'R':
					cPaintColorFlag = 'r';
					InvalidateRect(hwnd, NULL, TRUE);
					break;

				default:
					cPaintColorFlag = 'w';
					InvalidateRect(hwnd, NULL, TRUE);
					break;
					break;
			}
			break;

		case WM_PAINT:
			GetClientRect(hwnd, &rc);
			hdc = BeginPaint(hwnd, &ps);
			SetBkColor(hdc, RGB(0, 0, 0));

			if (cPaintColorFlag == 'v')
			{
				SetTextColor(hdc, RGB(148, 0, 211));
			}

			if (cPaintColorFlag == 'i')
			{
				SetTextColor(hdc, RGB(75, 0, 130));
			}

			if (cPaintColorFlag == 'b')
			{
				SetTextColor(hdc, RGB(0, 0, 255));
			}

			if (cPaintColorFlag == 'g')
			{
				SetTextColor(hdc, RGB(0, 255, 0));
			}

			if (cPaintColorFlag == 'y')
			{
				SetTextColor(hdc, RGB(255, 255, 0));
			}

			if (cPaintColorFlag == 'o')
			{
				SetTextColor(hdc, RGB(255, 127, 0));
			}

			if (cPaintColorFlag == 'r')
			{
				SetTextColor(hdc, RGB(255, 0, 0));
			}

			if (cPaintColorFlag == 'w')
			{
				SetTextColor(hdc, RGB(255, 255, 255));
			}
			
			TextOut(hdc, 16, 16, "Color Choices :: ", sizeof("Voilet - v/V"));
			TextOut(hdc, 16, 32, "Voilet - v/V", sizeof("Voilet - v/V"));
			TextOut(hdc, 16, 48, "Indigo - i/I", sizeof("Indigo - i/I"));
			TextOut(hdc, 16, 64, "Blue - b/B", sizeof("Blue - b/B"));
			TextOut(hdc, 16, 80, "Green - g/G", sizeof("Green - g/G"));
			TextOut(hdc, 16, 96, "Yellow - y/Y", sizeof("Yellow - y/Y"));
			TextOut(hdc, 16, 112, "Orange - o/O", sizeof("Orange - o/O"));
			TextOut(hdc, 16, 128, "Red - r/Red", sizeof("Red - r/Red"));
			TextOut(hdc, 16, 144, "Default - w/W", sizeof("Default - w/W"));

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