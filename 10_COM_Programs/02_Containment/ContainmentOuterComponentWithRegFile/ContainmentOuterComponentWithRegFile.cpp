//Header Declaration
#include <windows.h>

//Combined Header
#include "ClientOfContainmentComponentWithRegFile.h"

//Class Declaration
class CSumSubtract:public ISum, ISubtract, IMultiplication, IDivision
{
	private:
		long m_cRef;
		IMultiplication* m_pIMultiplication;
		IDivision* m_pIDivision;

	public:
		//Constructor Method Declaration
		CSumSubtract(void);

		//Destructor Method Declaration
		~CSumSubtract(void);

		//IUnknown Specific Method Declaration(Inherited)
		HRESULT __stdcall QueryInterface(REFIID, void**);
		ULONG __stdcall AddRef(void);
		ULONG __stdcall Release(void);

		//ISum Specific Method Declaration
		HRESULT __stdcall SumOfTwoIntegers(int, int, int*);

		//ISubtract Specific Method Declaration
		HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*);

		//IMultiplication Specific Method Declaration
		HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*);

		//IDivision Specific Method Declaration
		HRESULT __stdcall DivisionOfTwoIntegers(int, int, int*);

		//Custom Method For Inner Component Creation
		HRESULT __stdcall InitializeInnerComponent(void);
};

class CSumSubtractClassFactory:public IClassFactory
{
	private:
		long m_cRef;

	public:
		//Constructor Method Declaration
		CSumSubtractClassFactory(void);

		//Destructor Method Declaration
		~CSumSubtractClassFactory(void);

		//IUnknown Specific Method Declaration(Inherited)
		HRESULT __stdcall QueryInterface(REFIID, void**);
		ULONG __stdcall AddRef(void);
		ULONG __stdcall Release(void);

		//IClassFactory Specific Method Declaration(Inherited)
		HRESULT __stdcall CreateInstance(IUnknown*, REFIID, void**);
		HRESULT __stdcall LockServer(BOOL);
};

//Global Variable Declaration
long glNumberOfActiveComponents = 0;
long glNumberOfServerLocks = 0;

//DllMain() Definition
BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID Reserved)
{
	//Code
	switch(dwReason)
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

//Implementation Of CSumSubtract's Constructor Method
CSumSubtract::CSumSubtract(void)
{
	//Code
	m_pIMultiplication = NULL;
	m_pIDivision = NULL;
	m_cRef = 1;

	InterlockedIncrement(&glNumberOfActiveComponents);
}

//Implementation Of CSumSubtract's Destructor Method
CSumSubtract::~CSumSubtract(void)
{
	//Code
	InterlockedDecrement(&glNumberOfActiveComponents);
	if(m_pIMultiplication)
	{
		m_pIMultiplication->Release();
		m_pIMultiplication = NULL;
	}

	if(m_pIDivision)
	{
		m_pIDivision->Release();
		m_pIDivision = NULL;
	}	
}

//Implementation Of CSumSubtract's IUnknown's Methods
HRESULT CSumSubtract::QueryInterface(REFIID riid, void** ppv)
{
	//Code
	if(riid == IID_IUnknown)
		*ppv = static_cast<ISum*>(this);
	else if(riid == IID_ISum)
		*ppv = static_cast<ISum*>(this);
	else if(riid == IID_ISubtract)
		*ppv = static_cast<ISubtract*>(this);
	else if(riid == IID_IMultiplication)
		*ppv = static_cast<IMultiplication*>(this);
	else if(riid == IID_IDivision)
		*ppv = static_cast<IDivision*>(this);
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
	if(m_cRef == 0)
	{
		delete(this);
		return(0);
	}

	return(m_cRef);
}

//Implementation Of ISum's Methods
HRESULT CSumSubtract::SumOfTwoIntegers(int iFirstNumber, int iSecondNumber, int* iSumResult)
{
	//Code
	*iSumResult = iFirstNumber + iSecondNumber;
	return(S_OK);
}

//Implementation Of ISubtract's Methods
HRESULT CSumSubtract::SubtractionOfTwoIntegers(int iFirstNumber, int iSecondNumber, int* iSubtractResult)
{
	//Code
	*iSubtractResult = iFirstNumber - iSecondNumber;
	return(S_OK);
}

//Implementation Of IMultiplication's Methods
HRESULT CSumSubtract::MultiplicationOfTwoIntegers(int iFirstNumber, int iSecondNumber, int* iMultiplicationResult)
{
	//Code
	m_pIMultiplication->MultiplicationOfTwoIntegers(iFirstNumber, iSecondNumber, iMultiplicationResult);
	return(S_OK);
}

//Implementation Of IDivision's Methods
HRESULT CSumSubtract::DivisionOfTwoIntegers(int iFirstNumber, int iSecondNumber, int* iDivisionResult)
{
	//Code
	m_pIDivision->DivisionOfTwoIntegers(iFirstNumber, iSecondNumber, iDivisionResult);
	return(S_OK);
}

HRESULT CSumSubtract::InitializeInnerComponent(void)
{
	//Local Variable Declaration
	HRESULT hResult;

	//Code
	hResult = CoCreateInstance(CLSID_MultiplicationDivision, NULL, CLSCTX_INPROC_SERVER, IID_IMultiplication, (void**)&m_pIMultiplication);
	if(FAILED(hResult))
	{
		MessageBox(NULL,
		TEXT("IMultiplication Interface Cannot Be Obtained From Inner Component"),
		TEXT("CoCreateInstance() Failed"),
		MB_OK);
		return(E_FAIL);
	}

	hResult = m_pIMultiplication->QueryInterface(IID_IDivision, (void**)&m_pIDivision);
	if(FAILED(hResult))
	{
		MessageBox(NULL,
		TEXT("IDivision Interface Cannot Be Obtained From Inner Component"),
		TEXT("QueryInterface() Failed"),
		MB_OK);
		return(E_FAIL);
	}

	return(S_OK);
}

//Implementation Of CSumSubtractClassFactory's Constructor Method
CSumSubtractClassFactory::CSumSubtractClassFactory(void)
{
	//Code
	m_cRef = 1;
}

//Implementation Of CSumSubtractClassFactory's Destructor Method
CSumSubtractClassFactory::~CSumSubtractClassFactory(void)
{
	//Code
}

//Implementation Of CSumSubtractClassFactory's IClassFactory's IUnknown's Method
HRESULT CSumSubtractClassFactory::QueryInterface(REFIID riid, void** ppv)
{
	//Code
	if(riid == IID_IUnknown)
		*ppv = static_cast<IClassFactory*>(this);
	else if(riid == IID_IClassFactory)
		*ppv = static_cast<IClassFactory*>(this);
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
	if(m_cRef == 0)
	{
		delete(this);
		return(0);
	}

	return(m_cRef);
}

//Implementation Of CSumSubtractClassFactory's IClassFactory's Methods
HRESULT CSumSubtractClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv)
{
	//Local Variable Declaration
	CSumSubtract* pCSumSubtract = NULL;
	HRESULT hResult;

	//Code
	if(pUnkOuter != NULL)
		return(CLASS_E_NOAGGREGATION);

	pCSumSubtract = new CSumSubtract;
	if(pCSumSubtract == NULL)
		return(E_OUTOFMEMORY);

	hResult = pCSumSubtract->InitializeInnerComponent();
	if(FAILED(hResult))
	{
		MessageBox(NULL,
		TEXT("Failed To Initialize Inner Component"),
		TEXT("InitializeInnerComponent() Failed"),
		MB_OK);
		return(hResult);
	}

	hResult = pCSumSubtract->QueryInterface(riid, ppv);
	pCSumSubtract->Release();

	return(hResult);
}

HRESULT CSumSubtractClassFactory::LockServer(BOOL fLock)
{
	//Code
	if(fLock)
		InterlockedIncrement(&glNumberOfServerLocks);
	else
		InterlockedDecrement(&glNumberOfServerLocks);

	return(S_OK);
}

//Implementation Of Exported Functions From This DLL
HRESULT __stdcall DllGetClassObject(REFCLSID rcclsid, REFIID riid, void** ppv)
{
	//Local Variable Declaration
	CSumSubtractClassFactory* pCSumSubtractClassFactory = NULL;
	HRESULT hResult;

	//Code
	if(rcclsid != CLSID_SumSubtract)
		return(CLASS_E_CLASSNOTAVAILABLE);

	pCSumSubtractClassFactory = new CSumSubtractClassFactory;
	if(pCSumSubtractClassFactory == NULL)
		return(E_OUTOFMEMORY);

	hResult = pCSumSubtractClassFactory->QueryInterface(riid, ppv);
	pCSumSubtractClassFactory->Release();

	return(hResult);
}

HRESULT __stdcall DllCanUnloadNow(void)
{
	//Code
	if((glNumberOfActiveComponents == 0) && (glNumberOfServerLocks == 0))
		return(S_OK);
	else
		return(S_FALSE);
}
