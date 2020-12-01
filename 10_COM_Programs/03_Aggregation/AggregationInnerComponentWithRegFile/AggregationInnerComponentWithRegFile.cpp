//Header Declaration
#include <Windows.h>
#include "AggregationInnerComponentWithRegFile.h"

interface INoAggregationIUnknown
{
    virtual HRESULT __stdcall QueryInterface_NoAggregation(REFIID, void**) = 0;
    virtual ULONG __stdcall AddRef_NoAggregation(void) = 0;
    virtual ULONG __stdcall Release_NoAggregation(void) = 0;
};

//Class Declaration
class CMultiplicationDivision:public INoAggregationIUnknown, IMultiplication, IDivision
{
    private:
        long m_cRef;
        IUnknown *m_pIUnknownOuter;

    public:
        //Constructor Method Declaration
        CMultiplicationDivision(IUnknown*);

        //Destructor Method Declaration
        ~CMultiplicationDivision(void);

        //Aggregation Supported IUnknown Specific Method Declaration(Inherited)
        HRESULT __stdcall QueryInterface(REFIID, void**);
        ULONG __stdcall AddRef(void);
        ULONG __stdcall Release(void);

        //Aggregation Non-Supported IUnknown Specific Method Declaration(Inherited)
        HRESULT __stdcall QueryInterface_NoAggregation(REFIID, void**);
        ULONG __stdcall AddRef_NoAggregation(void);
        ULONG __stdcall Release_NoAggregation(void);

        //IMultiplication Specific Method Declaration(Inherited)
        HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*);

        //IDivision Specific Method Declaration(Inherited)
        HRESULT __stdcall DivisionOfTwoIntegers(int, int, int*);
};

class CMultiplicationDivisionClassFactory:public IClassFactory
{
    private:
        long m_cRef;

    public:
        //Constructor Method Declaration
        CMultiplicationDivisionClassFactory(void);

        //Destructor Method Declaration
        ~CMultiplicationDivisionClassFactory(void);

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

//Implementation Of CMultiplicationDivision's Constructor Method
CMultiplicationDivision::CMultiplicationDivision(IUnknown* pIUnknownOuter)
{
    //Code
    m_cRef = 1;
    InterlockedIncrement(&glNumberOfActiveComponents);
    if(pIUnknownOuter = NULL)
        m_pIUnknownOuter = pIUnknownOuter;
    else
        m_pIUnknownOuter = reinterpret_cast<IUnknown*>(static_cast<INoAggregationIUnknown*>(this));
}

//Implementation Of CMultiplicationDivision's Destructor Method
CMultiplicationDivision::~CMultiplicationDivision(void)
{
    //Code
    InterlockedDecrement(&glNumberOfActiveComponents);
}

//ImplementationOf CMultiplicationDivision's Aggregation Supporting IUnknown's Methods
HRESULT CMultiplicationDivision::QueryInterface(REFIID riid, void** ppv)
{
    //Code
    return(m_pIUnknownOuter->QueryInterface(riid, ppv));
}

ULONG CMultiplicationDivision::AddRef(void)
{
    //Code
    return(m_pIUnknownOuter->AddRef());
}

ULONG CMultiplicationDivision::Release(void)
{
    //Code
    return(m_pIUnknownOuter->Release());
}

//Implementation Of CMultiplicationDivision's Aggregation Non-Supporting IUnknown's Methods
HRESULT CMultiplicationDivision::QueryInterface_NoAggregation(REFIID riid, void** ppv)
{
    //Code
    if(riid == IID_IUnknown)
        *ppv = static_cast<INoAggregationIUnknown*>(this);
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

ULONG CMultiplicationDivision::AddRef_NoAggregation(void)
{
    //Code
    InterlockedIncrement(&m_cRef);
    return(m_cRef);
}

ULONG CMultiplicationDivision::Release_NoAggregation(void)
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

//Implementation Of IMultiplication's Methods
HRESULT CMultiplicationDivision::MultiplicationOfTwoIntegers(int iFirstNumber, int iSecondNumber, int* piMultiplicationResult)
{
    //Code
    *piMultiplicationResult = iFirstNumber * iSecondNumber;
    return(S_OK);
}

//Implementation Of IDivision's Methods
HRESULT CMultiplicationDivision::DivisionOfTwoIntegers(int iFirstNumber, int iSecondNumber, int* piDivisionResult)
{
    //Code
    *piDivisionResult = iFirstNumber / iSecondNumber;
    return(S_OK);
}

//Implementation Of CMultiplicationDivisionClassFactory's Constructor Method
CMultiplicationDivisionClassFactory::CMultiplicationDivisionClassFactory(void)
{
    //Code
    m_cRef = 1;
}

//Implementation Of CMultiplicationDivisionClassFactory's Destructor Method
CMultiplicationDivisionClassFactory::~CMultiplicationDivisionClassFactory(void)
{
    //Code
}

//Implementation Of CMultiplicationDivisionClassFactory's IClassFactory's IUnknow's Methods
HRESULT CMultiplicationDivisionClassFactory::QueryInterface(REFIID riid, void** ppv)
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

ULONG CMultiplicationDivisionClassFactory::AddRef(void)
{
    //Code
    InterlockedIncrement(&m_cRef);
    return(m_cRef);
}

ULONG CMultiplicationDivisionClassFactory::Release(void)
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

//Implementation Of CMultiplicationDivisionClassFactory's IClassFactory's Methods
HRESULT CMultiplicationDivisionClassFactory::CreateInstance(IUnknown* pIUnkOuter, REFIID riid, void** ppv)
{
    //Local Variable Declaration
    CMultiplicationDivision* pCMultiplicationDivision = NULL;
    HRESULT hResult;

    //Code
    if((pIUnkOuter != NULL) && (riid != IID_IUnknown))
        return(CLASS_E_NOAGGREGATION);

    pCMultiplicationDivision = new CMultiplicationDivision(pIUnkOuter);
    if(pCMultiplicationDivision == NULL)
        return(E_OUTOFMEMORY);

    hResult = pCMultiplicationDivision->QueryInterface_NoAggregation(riid, ppv);
    pCMultiplicationDivision->Release_NoAggregation();

    return(hResult);
}

HRESULT CMultiplicationDivisionClassFactory::LockServer(BOOL fLock)
{
    //Code
    if(fLock)
        InterlockedIncrement(&glNumberOfServerLocks);
    else
        InterlockedDecrement(&glNumberOfServerLocks);

    return(S_OK);
}

//Implementation Of Exported Functions From This DLL
HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
    //Local Variable Declaration
    CMultiplicationDivisionClassFactory *pCMultiplicationDivisionClassFactory = NULL;
    HRESULT hResult;

    //Code
    if(rclsid != CLSID_MultiplicationDivision)
        return(CLASS_E_CLASSNOTAVAILABLE);

    pCMultiplicationDivisionClassFactory = new CMultiplicationDivisionClassFactory;
    if(pCMultiplicationDivisionClassFactory == NULL)
        return(E_OUTOFMEMORY);
    
    hResult = pCMultiplicationDivisionClassFactory->QueryInterface(riid, ppv);
    pCMultiplicationDivisionClassFactory->Release();

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
