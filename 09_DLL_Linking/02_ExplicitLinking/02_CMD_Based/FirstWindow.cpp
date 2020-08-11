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
	//Local Variable Declaration
	HMODULE hDll = NULL;
	int iNumber = 5;
	int iResult;
	char szResult[255];
	typedef int (*MakeSquareFuntionPointer)(int);
	MakeSquareFuntionPointer makeSquareFunctionPointer = NULL;
	
	//Code
	switch (iMessage)
	{
		//First Messaage To Be Received
		case WM_CREATE:
			hDll = LoadLibrary(TEXT("08_MyMath.dll"));
			
			if(hDll == NULL)
			{
				MessageBox(hwnd,
				TEXT("LoadLibrary() failed..."),
				TEXT("Error"),
				MB_OK);
				DestroyWindow(hwnd);
			}
			
			makeSquareFunctionPointer = (MakeSquareFuntionPointer)GetProcAddress(hDll, "MakeSquare");
			if(makeSquareFunctionPointer == NULL)
			{
				hDll = NULL;
				MessageBox(hwnd,
				TEXT("GetProcAddress() failed..."),
				TEXT("Error"),
				MB_OK);
				DestroyWindow(hwnd);
			}
			
			iResult = makeSquareFunctionPointer(iNumber);
			wsprintf(szResult, TEXT("Square of %d is %d"), iNumber, iResult);

			MessageBox(hwnd,
				szResult,
				TEXT("Square Result"),
				MB_OK);
			break;

		//Last Message To Be Received
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}

	return(DefWindowProc(hwnd, iMessage, wParam, lParam));
}