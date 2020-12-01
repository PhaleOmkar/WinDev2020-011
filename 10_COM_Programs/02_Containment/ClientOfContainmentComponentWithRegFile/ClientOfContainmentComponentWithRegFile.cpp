//Header Declaration
#include <windows.h>
#include "ClientOfContainmentComponentWithRegFile.h"

//Global Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Global Variable Declaration
ISum* pISum = NULL;
ISubtract* pISubtract = NULL;
IMultiplication* pIMultiplication = NULL;
IDivision* pIDivision = NULL;

//WinMain() Definition
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//Local Variable Declaration
	WNDCLASSEX wndclassex;
	HWND hwnd;
	HRESULT hResult;
	MSG message;
	TCHAR szAppName[] = TEXT("ClientOfContainmentComponentWithRegFile");

	//Code
	//COM Initialization
	hResult = CoInitialize(NULL);
	if(FAILED(hResult))
	{
		MessageBox(NULL,
			TEXT("COM Library Cannot Be Initialized.\nProgram Will Now Exit..."),
			TEXT("CoInitialize() Failed"),
			MB_OK);
		exit(0);
	}
	
	//WNDCLASSEX Initialization
	wndclassex.cbSize = sizeof(wndclassex);
	wndclassex.style = CS_HREDRAW | CS_VREDRAW;
	wndclassex.cbClsExtra = 0;
	wndclassex.cbWndExtra = 0;
	wndclassex.lpfnWndProc = WndProc;
	wndclassex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclassex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclassex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclassex.hInstance = hInstance;
	wndclassex.lpszClassName = szAppName;
	wndclassex.lpszMenuName = NULL;
	wndclassex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	
	//Register Window Class
	RegisterClassEx(&wndclassex);
	
	//Create Window
	hwnd = CreateWindow(szAppName,
		TEXT("Client Of Containment Component With Reg File"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
		
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	
	//Message Loop
	while(GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	
	//COM Uninitialization
	CoUninitialize();
	return((int)message.wParam);
}

//WndProc() Definition
LRESULT WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//Local Function Declaration
	void SafeInterfaceRelease(void);
	
	//Local Variable Declaration
	HRESULT hResult;
	int ifirstNumber, isecondNumber, isumResult, isubtractResult, imultiplicationResult, idivisionResult;
	TCHAR szResult[255];

	//Code
	switch(iMessage)
	{
		case WM_CREATE:
			hResult = CoCreateInstance(CLSID_SumSubtract, NULL, CLSCTX_INPROC_SERVER, IID_ISum, (void**)&pISum);
			if(FAILED(hResult))
			{
				MessageBox(hwnd,
				TEXT("ISum Interface Cannot Be Obtained"),
				TEXT("CoCreateInstance() Failed"),
				MB_OK);

				DestroyWindow(hwnd);
			}

			ifirstNumber = 65;
			isecondNumber = 45;

			pISum->SumOfTwoIntegers(ifirstNumber, isecondNumber, &isumResult);
			wsprintf(szResult, TEXT("Sum of %d And %d = %d"), ifirstNumber, isecondNumber, isumResult);
			MessageBox(hwnd,
			szResult,
			TEXT("Result::SumOfTwoIntegers()"),
			MB_OK);

			hResult = pISum->QueryInterface(IID_ISubtrat, (void**)&pISubtract);
			if(FAILED(hResult))
			{
				MessageBox(hwnd,
				TEXT("ISubtract Interface Cannot Be Obtained"),
				TEXT("QueryInterface() Failed"),
				MB_OK);

				DestroyWindow(hwnd);
			}

			pISum->Release();
			pISum = NULL;
			/***********************************/

			ifirstNumber = 155;
			isecondNumber = 55;
			pISubtract->SubtractionOfTwoIntegers(ifirstNumber, isecondNumber, &isubtractResult);
			wsprintf(szResult, TEXT("Subtraction of %d And %d = %d"), ifirstNumber, isecondNumber, isubtractResult);
			MessageBox(hwnd,
			szResult,
			TEXT("Result::SubtractionOfTwoIntegers()"),
			MB_OK);

			hResult = pISubtract->QueryInterface(IID_IMultiplication, (void**)&pIMultiplication);
			if(FAILED(hResult))
			{
				MessageBox(hwnd,
				TEXT("IMultiplication Interface Cannot Be Obtained"),
				TEXT("QueryInterface() Failed"),
				MB_OK);

				DestroyWindow(hwnd);
			}

			pISubtract->Release();
			pISubtract = NULL;
			/***********************************/

			ifirstNumber = 30;
			isecondNumber = 25;
			pIMultiplication->MultiplicationOfTwoIntegers(ifirstNumber, isecondNumber, &imultiplicationResult);
			wsprintf(szResult, TEXT("Multiplication of %d And %d = %d"), ifirstNumber, isecondNumber, imultiplicationResult);
			MessageBox(hwnd,
			szResult,
			TEXT("Result::MultiplicationOfTwoIntegers()"),
			MB_OK);

			hResult = pIMultiplication->QueryInterface(IID_IDivision, (void**)&pIDivision);
			if(FAILED(hResult))
			{
				MessageBox(hwnd,
				TEXT("IDivision Interface Cannot Be Obtained"),
				TEXT("QueryInterface() Failed"),
				MB_OK);

				DestroyWindow(hwnd);
			}

			pIMultiplication->Release();
			pIMultiplication = NULL;
			/***********************************/

			ifirstNumber = 200;
			isecondNumber = 25;
			pIDivision->DivisionOfTwoIntegers(ifirstNumber, isecondNumber, &idivisionResult);
			wsprintf(szResult, TEXT("Division of %d And %d = %d"), ifirstNumber, isecondNumber, idivisionResult);
			MessageBox(hwnd,
			szResult,
			TEXT("Result::DivisionOfTwoIntegers()"),
			MB_OK);

			pIDivision->Release();
			pIDivision = NULL;

			DestroyWindow(hwnd);
			break;
			
		case WM_DESTROY:
			SafeInterfaceRelease();
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
	if(pISum)
	{
		pISum->Release();
		pISum = NULL;
	}

	if(pISubtract)
	{
		pISubtract->Release();
		pISubtract = NULL;
	}

	if(pIMultiplication)
	{
		pIMultiplication->Release();
		pIMultiplication = NULL;
	}

	if(pIDivision)
	{
		pIDivision->Release();
		pIDivision = NULL;
	}
}
