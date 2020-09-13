#define UNICODE

//Header file declaratioin
#include <windows.h>
#include "ClassFactoryDllServerWithRegFile.h"

//Class Declaration
class CSumSubtract:public ISum, ISubtract
{
private:
	long m_cRef;

public:
	//Constructor of CSumSubtract
	CSumSubtract(void);

	//Destructor of CSumSubtract
	~CSumSubtract(void);

	//IUnknown specific method declaration(Must be inherited)
	HRESULT _stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//ISum specific method declaration(Must be inherited)
	HRESULT __stdcall SumOfTwoIntegers(int, int, int*);

	//ISubtract specific method declaration(Must be inherited)
	HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*);
};

class CSumSubtractClassFactory:public IClassFactory
{
private:
	long m_cRef;

public:
	//Constructo of CSumSubtractClassFactory
	CSumSubtractClassFactory(void);

	//Destructor of CSumSubtractClassFactory
	~CSumSubtractClassFactory(void);

	//IUnknown specific method declaration(Must be inherited)
	HRESULT _stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IClassFactory specific method declaration(Must be inherited)
	HRESULT __stdcall CreateInstance(IUnknown*, REFIID, void**);
	HRESULT __stdcall LockServer(BOOL);
};

//Global Variable Declaration
long glNumberOfActiveComponents = 0; //Number of active components
long glNumberOfServerLocks = 0; //Number of server locks on this DLL

//DllMain() Defiinition
BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
	//Code
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		break;

	default:
		break;
	}

	return(TRUE);
}

//Implementation constructor of CSumSubtract
CSumSubtract::CSumSubtract(void)
{
	//Code
	m_cRef = 1;
	InterlockedIncrement(&glNumberOfActiveComponents);
}

//Implementation of destructor of CSumSubtract
CSumSubtract::~CSumSubtract(void)
{
	InterlockedDecrement(&glNumberOfActiveComponents);
}

//Implementation of IUnknown methods inherited in CSumSubtract
HRESULT CSumSubtract::QueryInterface(REFIID rfIID, void** ppv)
{
	//Code
	if (rfIID == IID_IUnknown)
	{
		*ppv = static_cast<ISum*>(this);
	}

	else if (rfIID == IID_ISum)
	{
		*ppv = static_cast<ISum*>(this);
	}

	else if (rfIID == IID_ISubtract)
	{
		*ppv = static_cast<ISubtract*>(this);
	}

	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);
	}
	
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return(S_OK);
}

ULONG CSumSubtract::AddRef(void)
{
	//Code
	InterlockedIncrement(&m_cRef);
	return(m_cRef);
}

ULONG CSumSubtract::Release(void)
{
	//Code
	InterlockedDecrement(&m_cRef);
	if (m_cRef == 0)
	{
		delete(this);
		return(0);
	}

	return(m_cRef);
}

//Implementation of ISum methods
HRESULT CSumSubtract::SumOfTwoIntegers(int iNumber_One, int iNumber_Two, int* pOutSum)
{
	//Code
	*pOutSum = iNumber_One + iNumber_Two;
	return(S_OK);
}

//Implementation of ISubtract methods
HRESULT CSumSubtract::SubtractionOfTwoIntegers(int iNumber_One, int iNumber_Two, int* pOutSubtract)
{
	//Code
	*pOutSubtract = iNumber_One - iNumber_Two;
	return(S_OK);
}

//Implementation of constructor of CSumSubtractClassFactory 
CSumSubtractClassFactory::CSumSubtractClassFactory(void)
{
	//Code
	m_cRef = 1;
}

//Implementation of destructor of CSumSubtractClassFactory 
CSumSubtractClassFactory::~CSumSubtractClassFactory(void)
{
	//Code
}

//Implementation of IUnknown methods inherited in CSumSubtractClassFactory
HRESULT CSumSubtractClassFactory::QueryInterface(REFIID rfIID, void** ppv)
{
	//Code
	if (rfIID == IID_IUnknown)
	{
		*ppv = static_cast<IClassFactory*>(this);
	}

	else if (rfIID == IID_IClassFactory)
	{
		*ppv = static_cast<IClassFactory*>(this);
	}

	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);
	}

	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return(S_OK);
}

ULONG CSumSubtractClassFactory::AddRef(void)
{
	//Code
	InterlockedIncrement(&m_cRef);
	return(m_cRef);
}

ULONG CSumSubtractClassFactory::Release(void)
{
	//Code
	InterlockedDecrement(&m_cRef);
	if (m_cRef == 0)
	{
		delete(this);
		return(0);
	}

	return(m_cRef);
}

//Implementation of CSumSubtractClassFactory methods
HRESULT CSumSubtractClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID rfIID, void** ppv)
{
	//Local variable declaration
	CSumSubtract* pCSumSubtract = NULL;
	HRESULT hResult;

	//Code
	if (pUnkOuter != NULL)
	{
		return(CLASS_E_NOAGGREGATION);
	}

	//Create instance of component i.e. of CSumSubtract
	pCSumSubtract = new CSumSubtract;
	if (pCSumSubtract == NULL)
	{
		return(E_OUTOFMEMORY);
	}

	//Get the requested interface
	hResult = pCSumSubtract->QueryInterface(rfIID, ppv);
	pCSumSubtract->Release();
	return(hResult);
}

HRESULT CSumSubtractClassFactory::LockServer(BOOL fLock)
{
	//Code
	if (fLock)
	{
		InterlockedIncrement(&glNumberOfServerLocks);
	}

	else
	{
		InterlockedDecrement(&glNumberOfServerLocks);
	}

	return(S_OK);
}

//Implementation of exported functions from DLL
HRESULT __stdcall DllGetClassObject(REFCLSID refClsId, REFIID rfIID, void** ppv)
{
	//Local variable declaration
	CSumSubtractClassFactory* pCSumSubtractClassFactory = NULL;
	HRESULT hResult;

	//Code
	if (refClsId != CLSID_SumSubtract)
	{
		return(CLASS_E_CLASSNOTAVAILABLE);
	}

	pCSumSubtractClassFactory = new CSumSubtractClassFactory;
	if (pCSumSubtractClassFactory == NULL)
	{
		return(E_OUTOFMEMORY);
	}

	hResult = pCSumSubtractClassFactory->QueryInterface(rfIID, ppv);
	pCSumSubtractClassFactory->Release();

	return(hResult);
}

HRESULT __stdcall DllCanUnloadNow(void)
{
	//Code
	if ((glNumberOfActiveComponents == 0) && (glNumberOfServerLocks == 0))
	{
		return(S_OK);
	}

	else
	{
		return(S_FALSE);
	}
}
