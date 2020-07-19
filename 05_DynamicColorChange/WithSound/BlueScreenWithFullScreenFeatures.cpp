//Header File Declaration
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <gl/GL.h>
#include "BlueScreenWithFullScreenFeatures.h"

//Global Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Macro Definitions
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define UD_TIMER 4896
#define UD_TIME_VALUE 110
#define UD_FACTOR 0.1f

//Pragma Declaration
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")

//Global Variable Declaration
DWORD dwStyle;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
HWND ghwnd = NULL;
HDC ghdc = NULL;
HGLRC ghrc = NULL;
FILE* gpFile;
bool gbFullScreen = false;
bool gbActiveWindow = false;
bool bRedColorMax = false;
bool bGreenColorMax = false;
bool bBlueColorMax = false;
float fRedColor;
float fGreenColor;
float fBlueColor;

//WinMain() Defintion
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Local Funtion Declaration
	void Initialize(void);
	
	//Variable Declarations
	WNDCLASSEX wndclassex;
	HWND hwnd;
	MSG message;
	TCHAR szAppName[] = TEXT("FirstWindowUsingWin32");
	RECT rect;
	BOOL bResult;
	int iCenterX = 0;
	int iCenterY = 0;
	bool bDone = false;

	//Code
	//Error Checking Of 'fopen_s()'
	if (fopen_s(&gpFile, "CodeExecutionLog.txt", "w") != 0)
	{
		MessageBox(NULL,
			TEXT("Cannot open desire file"),
			TEXT("Message::fopen_s() failed"),
			MB_ICONERROR);
		exit(0);
	}

	else
	{
		fprintf(gpFile, "BEGIN::fopen_s() successful\tProgram execution started...\n\n");
	}
	
	//Getting System Parameters Info
	bResult = SystemParametersInfo(
		SPI_GETWORKAREA,
		0,
		&rect,
		0
	);

	//Error Checking :: bResult
	if (bResult == TRUE)
	{
		iCenterX = ((int)(rect.left + rect.right) - (int)(WINDOW_WIDTH)) / 2;
		iCenterY = ((int)(rect.top + rect.bottom) - (int)(WINDOW_HEIGHT)) / 2;
	}

	//Initialization Of WNDCLASSEX
	wndclassex.cbSize = sizeof(WNDCLASSEX);
	wndclassex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
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
	hwnd = CreateWindowEx(WS_EX_APPWINDOW,
		szAppName,
		TEXT("Omkar Phale RTR2020-112"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		iCenterX,
		iCenterY,
		(int)WINDOW_WIDTH,
		(int)WINDOW_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);

	//Copying Window Handle To Global Handle
	ghwnd = hwnd;

	//Initialize() Called
	Initialize();

	//Show And Update Window
	ShowWindow(hwnd, iCmdShow);
	
	//Setting ForeGroundWindow and Focus
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	//Game Loop
	while (bDone == false)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
			{
				bDone = true;
			}

			else
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
		}

		else
		{
			if (gbActiveWindow == true)
			{
			}
		}
	}

	return((int)message.wParam);
}

//WndProc() Definition
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//Function Declaration
	void ToogleFullScreen(void);
	void Resize(int, int);
	void Display(void);
	void Uninitialize(void);

	//Code
	switch (iMessage)
	{
		case WM_CREATE:
			PlaySound(TEXT("sample_long.wav"), NULL, SND_LOOP | SND_ASYNC);
			SetTimer(hwnd, UD_TIMER, UD_TIME_VALUE, NULL);
			break;

		case WM_TIMER:
			KillTimer(hwnd, UD_TIMER);
			
			//Red Color
			if (bRedColorMax == false)
			{
				fRedColor += UD_FACTOR;
				if (fRedColor > 1.0f)
				{
					bRedColorMax = true;
				}
			}
			else
			{
				fRedColor -= UD_FACTOR;
				if (fRedColor < 0.0f)
				{
					bRedColorMax = false;
					bGreenColorMax = false;
				}
			}
			
			//Green Color
			if (bGreenColorMax == false)
			{
				fGreenColor += UD_FACTOR;
				if (fGreenColor > 1.0f)
				{
					bGreenColorMax = true;
				}
			}
			else
			{
				fGreenColor -= UD_FACTOR;
				if (fGreenColor < 0.0f)
				{
					bGreenColorMax = false;
					//bBlueColorMax = false;
				}
			}

			/*
			//Blue Color
			if (bBlueColorMax == false)
			{
				fBlueColor += UD_FACTOR;
				if (fBlueColor > 1.0f)
				{
					bBlueColorMax = true;	
				}
			}
			else
			{
				fBlueColor -= UD_FACTOR;
				if (fBlueColor < 0.0f)
				{
					bBlueColorMax = false;
					bRedColorMax = false;
					//bGreenColorMax = true;
				}
			}
			*/

			InvalidateRect(hwnd, NULL, TRUE);
			SetTimer(hwnd, UD_TIMER, UD_TIME_VALUE, NULL);
			break;

		case WM_SETFOCUS:
			gbActiveWindow = true; 
			break;

		case WM_KILLFOCUS:
			gbActiveWindow = false;
			break;

		case WM_ERASEBKGND:
			return(0);

		case WM_SIZE:
			Resize(LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_PAINT:
			glClearColor(fRedColor, fGreenColor, fBlueColor, 1.0f);
			Display();
			break;

		case WM_KEYDOWN:
			fprintf(gpFile, "WM_KEYDOWN received\n");
			
			switch (wParam)
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

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}

	return(DefWindowProc(hwnd, iMessage, wParam, lParam));
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

//Initialize() Definition
void Initialize(void)
{
	fprintf(gpFile, "Ininitialize() started...\n");
	//Local Function Declaration
	void Resize(int, int);
	
	//Local Variable Declaration
	PIXELFORMATDESCRIPTOR pixelformatdescriptor;
	int iPixelFormatIndex;

	//Code
	ghdc = GetDC(ghwnd);
	ZeroMemory(&pixelformatdescriptor, sizeof(PIXELFORMATDESCRIPTOR));

	//Iniitialization of PIXELFORMATDESCRIPTOR
	pixelformatdescriptor.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pixelformatdescriptor.nVersion = 1;
	pixelformatdescriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
	pixelformatdescriptor.iPixelType = PFD_TYPE_RGBA;
	pixelformatdescriptor.cColorBits = 32;
	pixelformatdescriptor.cRedBits = 8;
	pixelformatdescriptor.cGreenBits = 8;
	pixelformatdescriptor.cBlueBits = 8;
	pixelformatdescriptor.cAlphaBits = 8;

	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pixelformatdescriptor);

	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFile, "ChoosePixelFormat() failed...\n");
		DestroyWindow(ghwnd);
	}

	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pixelformatdescriptor) == FALSE)
	{
		fprintf(gpFile, "SetPixelFormat() failed...\n");
		DestroyWindow(ghwnd);
	}

	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		fprintf(gpFile, "wglCreateContext() failed...\n");
		DestroyWindow(ghwnd);
	}

	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFile, "wglMakeCurrent() failed...\n");
		DestroyWindow(ghwnd);
	}

	//Set Clear Color
	glClearColor(sin(fRedColor), cos(fGreenColor), 0.0f, 1.0f);

	//Code
	Resize(WINDOW_WIDTH, WINDOW_HEIGHT);	//Warm Up Call To Resize()

	fprintf(gpFile, "Initialize() completed...\n\n");
}

//Display() Definition
void Display(void)
{
	//Code
	glClear(GL_COLOR_BUFFER_BIT);

	glFlush();
}

//Resize() Definition
void Resize(int iWidth, int iHeight)
{
	fprintf(gpFile, "Resize() started...\n");
	//Code
	if (iHeight == 0)
	{
		iHeight = 1;
	}

	glViewport(0, 0, (GLsizei)iWidth, (GLsizei)iHeight);

	fprintf(gpFile, "Resize() completed...\n\n");
}

//Unintialize() Definition
void Uninitialize(void)
{
	fprintf(gpFile, "Uninitialize() started...\n");
	//Code
	if (gbFullScreen == true)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);

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
	}

	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}

	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	//Closing 'gpFile'
	if (gpFile)
	{
		fprintf(gpFile, "Closing gpFile\tProgram completed successfully...\n");
		fclose(gpFile);
		gpFile = NULL;
	}

	fprintf(gpFile, "Uninitialize() completed...\n");
}
