//Header Files
#include <windows.h>
#include "SplashScreen.h"

//Macro Definition
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

//Gloabal Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK SplashWndProc(HWND, UINT, WPARAM, LPARAM);

//Gloabal Variable Declaration
HWND ghwndMain;
HBITMAP hSplashBMP;
HDC hSplashDC;
HDC hMemoryDC;
LONG BitmapWidth, BitmapHeight;
DWORD dwStyle;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
bool gbFullScreen = false;
HWND ghwnd = NULL;

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Variable Declaration
	WNDCLASSEX wndclassexMain, wndclassexSplash;
	HWND hwndMain, hwndSplash;
	MSG message;
	RECT rect;
	BITMAP Bitmap;
	TCHAR szAppName[] = TEXT("FirstWindow");
	TCHAR szSplashClassName[] = TEXT("FirstWindowSplash");

	//Code
	//WNDCLASSEX Initialization
	wndclassexMain.cbSize = sizeof(WNDCLASSEX);
	wndclassexMain.style = CS_HREDRAW | CS_VREDRAW;
	wndclassexMain.cbClsExtra = 0;
	wndclassexMain.cbWndExtra = 0;
	wndclassexMain.lpfnWndProc = WndProc;
	wndclassexMain.hInstance = hInstance;
	wndclassexMain.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclassexMain.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclassexMain.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclassexMain.lpszClassName = szAppName;
	wndclassexMain.lpszMenuName = NULL;
	wndclassexMain.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//Register WNDCLASSEX
	if( !RegisterClassEx(&wndclassexMain) )
	{
		MessageBox(NULL, 
			    TEXT("MainWindow::RegisterClassEx() Failed..."), 
				TEXT("MainWindow::Error"), 
				MB_OK | MB_ICONERROR);
        exit(0);
	}
	
	wndclassexSplash.cbSize = sizeof(WNDCLASSEX);
	wndclassexSplash.style = 0;
	wndclassexSplash.cbClsExtra = 0;
	wndclassexSplash.cbWndExtra = 0;
	wndclassexSplash.lpfnWndProc = SplashWndProc;
	wndclassexSplash.hInstance = hInstance;
	wndclassexSplash.hIcon = NULL;
	wndclassexSplash.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclassexSplash.hbrBackground = NULL;
	wndclassexSplash.lpszClassName = szSplashClassName;
	wndclassexSplash.lpszMenuName = NULL;
	wndclassexSplash.hIconSm = NULL;

	if( !RegisterClassEx(&wndclassexSplash) )
	{
		MessageBox(NULL, 
			    TEXT("SplashWindow::RegisterClassEx() Failed..."), 
				TEXT("SplashWindow::Error"), 
				MB_OK | MB_ICONERROR);
        exit(0);
	}
	
    GetWindowRect(GetDesktopWindow(), &rect);

	//Create Window
	hwndMain = CreateWindow(szAppName,
		TEXT("Omkar Phale"),
		WS_OVERLAPPEDWINDOW,
		(rect.right - WINDOW_WIDTH) / 2,
		(rect.bottom - WINDOW_HEIGHT) / 2,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);
		
	if (!hwndMain)
    {
        MessageBox(NULL, 
				TEXT("MainWindow::CreateWindow() Failed..."),
				TEXT("MainWindow::Error"),
				MB_OK | MB_ICONERROR);
        exit(0);
    }
	
	ghwndMain = hwndMain; 
	
	hSplashBMP = LoadBitmap(hInstance, MAKEINTRESOURCE(BITMAP_ID));
	
	if (!hSplashBMP)
    {
        MessageBox(NULL, 
				TEXT("SplashWindow::LoadBitmap() Failed..."),
				TEXT("SplashWindow::Error"),
				MB_OK | MB_ICONERROR);
        exit(0);
    }

    GetObject(hSplashBMP, sizeof(BITMAP), &Bitmap);
    BitmapWidth = Bitmap.bmWidth;
    BitmapHeight = Bitmap.bmHeight;

    hwndSplash = CreateWindowEx(WS_EX_TOPMOST,
		szSplashClassName,
		"Splash Screen",
		WS_POPUP,
		(rect.right - BitmapWidth) / 2,
		(rect.bottom - BitmapHeight) / 2,
		Bitmap.bmWidth,
		Bitmap.bmHeight,
		NULL,
		NULL,
		hInstance,
		NULL);

    if (!hwndSplash)
    {
        MessageBox(NULL,
			TEXT("SplashWindow::Splash Window Creation Failed."),
			TEXT("SplashWindow::Error"),
			MB_OK | MB_ICONERROR);
        return 0;
    }

    hSplashDC = GetDC(hwndSplash);
    hMemoryDC = CreateCompatibleDC(hSplashDC);
    SelectObject(hMemoryDC, (HGDIOBJ)hSplashBMP);

	//Show Window
	ShowWindow(hwndSplash, iCmdShow);

	//Update Window
	UpdateWindow(hwndSplash);

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
	//Function Declaration
	void ToogleFullScreen(void);
	
	//Code
	switch (iMessage)
	{
		case WM_KEYDOWN:
			switch(wParam)
			{
				case VK_ESCAPE:
					DestroyWindow(hwnd);
					break;
				
				case 0x46:
				case 0x66:
					ToogleFullScreen();
					break;				
					
				default:
					break;
			}
			
			break;
			
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
			
		//Last Message To Be Received
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}

	return(DefWindowProc(hwnd, iMessage, wParam, lParam));
}

LRESULT CALLBACK SplashWndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    switch (iMessage)
    {
		
        case WM_ERASEBKGND:
            BitBlt((HDC)wParam, 0, 0, BitmapWidth, BitmapHeight, hMemoryDC, 0, 0, SRCCOPY); 
			break;

        case WM_CHAR:
        case WM_KILLFOCUS:
		case WM_LBUTTONDOWN:
        case WM_RBUTTONDOWN:
        case WM_MBUTTONDOWN:
			DestroyWindow(hwnd);
			break;
		
		case WM_DESTROY:
            DeleteObject(hSplashBMP);
            ReleaseDC(hwnd, hSplashDC);
            ReleaseDC(hwnd, hMemoryDC);
            DestroyWindow(hwnd);
			
            ShowWindow(ghwndMain, SW_SHOW);
            UpdateWindow(ghwndMain);
            SetForegroundWindow(ghwndMain);
			break;
	}
    
	return (DefWindowProc(hwnd, iMessage, wParam, lParam));
}

//ToggleFullScreen() Definition
void ToogleFullScreen(void)
{
	//Variable Declarations
	MONITORINFO monitorinfo = { sizeof(MONITORINFO) };

	//Code
	if (gbFullScreen == false)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);

		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &monitorinfo))
			{
				SetWindowLong(ghwnd, GWL_STYLE, (dwStyle & ~WS_OVERLAPPEDWINDOW));
				SetWindowPos(ghwnd,
					HWND_TOP,
					monitorinfo.rcMonitor.left,
					monitorinfo.rcMonitor.top,
					(monitorinfo.rcMonitor.right - monitorinfo.rcMonitor.left),
					(monitorinfo.rcMonitor.bottom - monitorinfo.rcMonitor.top),
					SWP_NOZORDER | SWP_FRAMECHANGED);
			}
		}

		ShowCursor(FALSE);
		gbFullScreen = true;
	}

	else
	{
		SetWindowLong(ghwnd, GWL_STYLE, (dwStyle | WS_OVERLAPPEDWINDOW));
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowPos(ghwnd,
			HWND_TOP,
			0,
			0,
			0,
			0,
			SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
		ShowCursor(TRUE);
		gbFullScreen = false;
	}
}
