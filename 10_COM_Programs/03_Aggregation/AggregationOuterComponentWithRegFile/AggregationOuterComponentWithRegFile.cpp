//Header Declaration
#include <windows.h>
#include "ClientOfAggregationComponentWithRegFile.h"

//Class Declaration
class CSumSubtract:public ISum, ISubtract
{
    private:
        long m_cRef;
        IUnknown* m_pIUnknownInner;
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
    //Initialization Of Private Data Members
    m_pIUnknownInner = NULL;
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

    if(m_pIUnknownInner)
    {
        m_pIUnknownInner->Release();
        m_pIUnknownInner = NULL;
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
        return(m_pIUnknownInner->QueryInterface(riid, ppv));
    else if(riid == IID_IDivision)
        return(m_pIUnknownInner->QueryInterface(riid, ppv));
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
    InterlockedIncrement(&glNumberOfActiveComponents);
    return(m_cRef);
}

ULONG CSumSubtract::Release(void)
{
    //Code
    InterlockedDecrement(&glNumberOfActiveComponents);
    if(m_cRef == 0)
    {
        delete(this);
        return(0);
    }

    return(m_cRef);
}

//Implementation Of ISum's Methods
HRESULT CSumSubtract::SumOfTwoIntegers(int iFirstNumber, int iSecondNumber, int* piSumResult)
{
    //Code
    *piSumResult = iFirstNumber + iSecondNumber;
    return(S_OK);
}

//Implementation Of ISubtract's Methods
HRESULT CSumSubtract::SubtractionOfTwoIntegers(int iFirstNumber, int iSecondNumber, int* piSubtractResult)
{
    //Code
    *piSubtractResult = iFirstNumber - iSecondNumber;
    return(S_OK);
}

HRESULT CSumSubtract::InitializeInnerComponent(void)
{
    //Local Variable Declaration
    HRESULT hResult;

    //Code
    hResult = CoCreateInstance(CLSID_MultiplicationDivision, reinterpret_cast<IUnknown*>(this), CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&m_pIUnknownInner);
    if(FAILED(hResult))
    {
        MessageBox(NULL,
        TEXT("IUnknown Interface Cannot Be Obtained From Inner Component"),
        TEXT("CoCreateInstance() Failed"),
        MB_OK);
        return(E_FAIL);
    }

    hResult = m_pIUnknownInner->QueryInterface(IID_IMultiplication, (void**)&m_pIMultiplication);
    if(FAILED(hResult))
    {
        MessageBox(NULL,
        TEXT("IMultiplication Interface Cannot Be Obtained From Inner Component"),
        TEXT("QueryInterface() Failed"),
        MB_OK);
        m_pIUnknownInner->Release();
        m_pIUnknownInner = NULL;
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

CSumSubtractClassFactory::~CSumSubtractClassFactory(void)
{
    //Code
}

//Implementation Of CSumSubtractClassFactory's IClassFactory's IUnknown's Methods
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

//Implementation Of CSumSubtratClassFactory's IClassFactory's Methods
HRESULT CSumSubtractClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv)
{
    //Local Variable Declaration
    CSumSubtract* pCSumSubtract = NULL;
    HRESULT hResult;

    //Code
    if(pUnkOuter != NULL)
        return(CLASS_E_NOAGGREGATION);

    //Create The Instance Of Component i.e. Of CSumSubtract Class
    pCSumSubtract = new CSumSubtract;
    if(pCSumSubtract == NULL)
        return(E_OUTOFMEMORY);
    
    //Initialize Inner Component
    hResult = pCSumSubtract->InitializeInnerComponent();
    if(FAILED(hResult))
    {
        MessageBox(NULL,
        TEXT("Failed To Initialize Inner Component"),
        TEXT("InitializeInnerComponent() Failed"),
        MB_OK);
        pCSumSubtract->Release();
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
       InterlockedIncrement(&glNumberOfActiveComponents); 
    else
        InterlockedDecrement(&glNumberOfActiveComponents);

    return(S_OK);
}

//Implementation Of Exported Functions From This DLL
HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
    //Local Variable Declaration
    CSumSubtractClassFactory* pCSumSubractClassFactory = NULL;
    HRESULT hResult;

    //Code
    if(rclsid != CLSID_SumSubtract)
        return(CLASS_E_CLASSNOTAVAILABLE);
    
    //Create Class Factory
    pCSumSubractClassFactory = new CSumSubtractClassFactory;
    if(pCSumSubractClassFactory == NULL)
        return(E_OUTOFMEMORY);
    
    hResult = pCSumSubractClassFactory->QueryInterface(riid, ppv);
    pCSumSubractClassFactory->Release();

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
