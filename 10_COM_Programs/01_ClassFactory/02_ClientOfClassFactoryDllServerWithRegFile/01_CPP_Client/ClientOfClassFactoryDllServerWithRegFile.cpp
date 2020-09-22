//Header file declaration
#include <windows.h>
#include "ClassFactoryDllServerWithRegFile.h"

//Global function declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Global variable declaration
ISum* gpISum = NULL;
ISubtract* gpISubtract = NULL;

//WinMain() Definition
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow)
{
	//Local variable declaration
	WNDCLASSEX wndclassex;
	HWND hwnd;
	MSG message;
	TCHAR szAppName[] = TEXT("ClassFactory::COM Client");
	HRESULT hResult;

	//Code
	//COM initialization
	hResult = CoInitialize(NULL);
	if (FAILED(hResult))
	{
		MessageBox(NULL,
			TEXT("COM Library Cannot Be Initialized.\nProgram Will Now EXIT."),
			TEXT("CoInitialize() Failed"),
			MB_OK);
		exit(0);
	}

	//WNDCLASSEX initializatio
	wndclassex.cbSize = sizeof(wndclassex);
	wndclassex.style = CS_HREDRAW | CS_VREDRAW;
	wndclassex.cbClsExtra = 0;
	wndclassex.cbWndExtra = 0;
	wndclassex.lpfnWndProc = WndProc;
	wndclassex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclassex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclassex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclassex.hInstance = hInstance;
	wndclassex.lpszClassName = szAppName;
	wndclassex.lpszMenuName = NULL;
	wndclassex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//Register window class
	if (!RegisterClassEx(&wndclassex))
	{
		MessageBox(NULL,
			TEXT("Program Will Now EXIT."),
			TEXT("RegisterClassEx() Failed"),
			MB_OK);
		exit(0);
	}

	//Create Window
	hwnd = CreateWindow(szAppName,
		TEXT("ClassFactory::Client in COM"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		NULL,
		NULL,
		hInstance,
		NULL);

	if (!hwnd)
	{
		MessageBox(NULL,
			TEXT("Program Will Now EXIT."),
			TEXT("hwnd Failed"),
			MB_OK);
		exit(0);
	}

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//Message loop
	while(GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	//COM un-initialization
	CoUninitialize();

	return((int)message.wParam);
}

//WndProc() Definition
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//Local function declaration
	void SafeInterfaceRelease(void);
	
	//Local variable declaration
	HRESULT hResult;
	int iNumber_One;
	int iNumber_Two;
	int iResult;
	TCHAR szResult[255];
	
	//Code
	switch(iMessage)
	{
	case WM_CREATE:
		hResult = CoCreateInstance(CLSID_SumSubtract, NULL, CLSCTX_INPROC_SERVER, IID_ISum, (void**)&gpISum);
		
		if (FAILED(hResult))
		{
			MessageBox(hwnd,
				TEXT("ISum interface cannot be obtained"),
				TEXT("IID_ISum::CoCreateInstance() Failed"),
				MB_OK);
			DestroyWindow(hwnd);
		}

		iNumber_One = 45;
		iNumber_Two = 55;

		gpISum->SumOfTwoIntegers(iNumber_One, iNumber_Two, &iResult);
		wsprintf(szResult, TEXT("%d + %d = %d"), iNumber_One, iNumber_Two, iResult);
		MessageBox(hwnd,
			szResult,
			TEXT("SumOfTwoIntegers() Result"),
			MB_OK);

		hResult = gpISum->QueryInterface(IID_ISubtract, (void**)&gpISubtract);
		if (FAILED(hResult))
		{
			MessageBox(hwnd,
				TEXT("ISubtract interface cannot be obtained"),
				TEXT("IID_ISubtract::QueryInterface() Failed"),
				MB_OK);
			DestroyWindow(hwnd);
		}

		gpISum->Release();
		gpISum = NULL;

		iNumber_One = 55;
		iNumber_Two = 45;

		gpISubtract->SubtractionOfTwoIntegers(iNumber_One, iNumber_Two, &iResult);
		wsprintf(szResult, TEXT("%d - %d = %d"), iNumber_One, iNumber_Two, iResult);
		MessageBox(hwnd,
			szResult,
			TEXT("SubtractionOfTwoIntegers() Result"),
			MB_OK);

		gpISubtract->Release();
		gpISubtract = NULL;
		
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	
	default:
		break;
	}

	return(DefWindowProc(hwnd, iMessage, wParam, lParam));
}

//SafeInterfaceRelease() Definition
void SafeInterfaceRelease(void)
{
	//Code
	if (gpISum)
	{
		gpISum->Release();
		gpISum = NULL;
	}

	if (gpISubtract)
	{
		gpISubtract->Release();
		gpISubtract = NULL;
	}
}
