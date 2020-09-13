# Steps to Create DLL by

------------------------
## 1. declspec method ##

A] Creating DLL
  
    + To create a DLL using declspec method we need to create a Dynamic Link Library project using Visual Studio(2019)
		- File -> New Project -> Windows Application Wizard -> Dynamic Link Library -> Empty Project -> SetPath

	+ Create a header file : MyMath.h
		- Add below code
		
		/*Pragma declaration*/
		#prgma once
		
		/*Exportable Function Prototype*/
		__declspec(dllexport) int MakeSquare(int);
		
	+ Create a source file : MyMath.cpp
		- Add below code
		
		/*Header file declaration*/
		#include <windows.h>
		#include "MyMath.h"
		
		/*Entry-Point Function*/
		BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
		{
			/*Code*/
			switch(dwReason)
			{
				case DLL_PROCESS_ATTACH:
					break;
				
				case DLL_THREAD_ATTACH:
					break;
					
				case DLL_THREAD_DETTACH:
					break;
					
				case DLL_PROCESS_DETTACH:
					break;
				
				default:
					break;
			}
			
			return(TRUE);
		}
		
		/*Exportable Function Definition*/
		__declspec(dllexport) int MakeSquare(int iNumeber)
		{
			/*Code*/
			return(iNumber [*] iNumber);
		}

	+ Now Clean -> Build -> Check newly created files(MyMath.dll, MyMath.lib)

B] Using newly created DLL 

    + Now edit the Window creation code as follows
		- Include header file which contains the MakeSquare() prototype
		/*Header file declaration*/
		#include "MyMath.h"

		- Include the library file of DLL
		/*Pragma Declaration*/
		#pragma comment(lib, "MyMath.lib")

		- No changes in WinMain()
		- Modify WndProc() as follows :
		
		/*Global Function Definition*/
		LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
		{
			/*Local Variable Declaration*/
			int iNumber = 5;
			int iResult;
			TCHAR szResult[255];

			/*Code*/
			switch (iMessage)
			{
			case WM_CREATE:
				iResult = MakeSquare(iNumber);
				wsprintf(szResult, TEXT("Square of %d is %d"), iNumber, iResult);

				MessageBox(hwnd,
					szResult,
					TEXT("Square Result"),
					MB_OK);
				break;

			case WM_DESTROY:
				PostQuitMessage(0);
				break;
			}

			return(DefWindowProc(hwnd, iMessage, wParam, lParam));
		}
------------------------

------------------------
## 2. def file method ##

A] Creating DLL
	
    + To create a DLL using declspec method we need to create a Dynamic Link Library project using Visual Studio(2019)
		- File -> New Project -> Windows Application Wizard -> Dynamic Link Library -> Empty Project -> SetPath

	+ Create a header file : MyMath.h
		- Add below code
		
		/*Pragma declaration*/
		#prgma once
		
		/*Exportable Function Prototype*/
		extern "C" int MakeSquare(int);
	
	+ Create a Module Definition File(MyMath.def)
		- Add below code 
		
		LIBRARY	MyMath	/*Name of target DLL file*/
		EXPORTS
				MakeSquare	/*Name of Exported function*/
		
	+ Create a source file : MyMath.cpp
		- Add below code
		
		/*Header file declaration*/
		#include <windows.h>
		#include "MyMath.h"
		
		/*Entry-Point Function*/
		BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
		{
			/*Code*/
			switch(dwReason)
			{
				case DLL_PROCESS_ATTACH:
					break;
				
				case DLL_THREAD_ATTACH:
					break;
					
				case DLL_THREAD_DETTACH:
					break;
					
				case DLL_PROCESS_DETTACH:
					break;
				
				default:
					break;
			}
			
			return(TRUE);
		}
		
		/*Exportable Function Definition*/
		extern "C" int MakeSquare(int iNumeber)
		{
			/*Code*/
			return(iNumber [*] iNumber);
		}

	+ Now Clean -> Build -> Check newly created files(MyMath.dll, MyMath.lib)

B] Using newly created DLL
	
    + Now edit the Window creation code as follows
		- Include header file which contains the MakeSquare() prototype
		/*Header file declaration*/
		#include "MyMath.h"

		- Include the library file of DLL
		/*Pragma Declaration*/
		#pragma comment(lib, "MyMath.lib")

		- No changes in WinMain()
		- Modify WndProc() as follows :
		
		/*Global Function Definition*/
		LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
		{
			/*Local Variable Declaration*/
			int iNumber = 5;
			int iResult;
			TCHAR szResult[255];

			/*Code*/
			switch (iMessage)
			{
			case WM_CREATE:
				iResult = MakeSquare(iNumber);
				wsprintf(szResult, TEXT("Square of %d is %d"), iNumber, iResult);

				MessageBox(hwnd,
					szResult,
					TEXT("Square Result"),
					MB_OK);
				break;

			case WM_DESTROY:
				PostQuitMessage(0);
				break;
			}

			return(DefWindowProc(hwnd, iMessage, wParam, lParam));
		}
------------------------