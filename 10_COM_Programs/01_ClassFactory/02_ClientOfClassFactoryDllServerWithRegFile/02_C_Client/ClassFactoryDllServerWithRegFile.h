#pragma once

#undef INTERFACE	//If INTERFACE is defined earlier, then temporarily undefine it

#define INTERFACE ISum

DECLARE_INTERFACE_(ISum, IUnknown)	//Analogous to Class ISum:public IUnknown
{
	//IUnknown Methods
	STDMETHOD(QueryInterface)(THIS_ REFIID, void**) PURE;	//HRESULT is the recommended return value :: STDMETHOD == HRESULT __stdcall HRESULT _stdcall QueryInterface(REFIID, void**);
	
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;	//ULONG __stdcall AddRef(void);
	
	STDMETHOD_(ULONG, Release)(THIS) PURE;	//ULONG __stdcall Release(void);

	//ISum Methods
	STDMETHOD(SumOfTwoIntegers)(THIS_ int, int, int*) PURE;
};

/******************************************************************************************/

#undef INTERFACE	//If INTERFACE is defined earlier, then temporarily undefine it

#define INTERFACE ISubtract

DECLARE_INTERFACE_(ISubtract, IUnknown)
{
	//IUnknown Methods
	STDMETHOD(QueryInterface)(THIS_ REFIID, void**) PURE;	//HRESULT is the recommended return value :: STDMETHOD == HRESULT __stdcall HRESULT _stdcall QueryInterface(REFIID, void**);
	
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;	//ULONG __stdcall AddRef(void);
	
	STDMETHOD_(ULONG, Release)(THIS) PURE;	//ULONG __stdcall Release(void);

	//ISubtract Methods
	STDMETHOD(SubtractionOfTwoIntegers)(THIS_ int, int, int*) PURE;
};

//CLSID of SumSubtract Component {0536A087-78D6-4497-983E-459BD206E3EB}
const CLSID CLSID_SumSubtract = {0x536a087, 0x78d6, 0x4497, 0x98, 0x3e, 0x45, 0x9b, 0xd2, 0x6, 0xe3, 0xeb};

//IID of ISum Interface {E2FC8473-99A7-41E4-AD0F-EC4DDE75F543}
const IID IID_ISum = {0xe2fc8473, 0x99a7, 0x41e4, 0xad, 0xf, 0xec, 0x4d, 0xde, 0x75, 0xf5, 0x43};

//IID of ISubtract Interface {B6364D61-2E08-49E0-A04C-C730406F7984}
const IID IID_ISubtract = {0xb6364d61, 0x2e08, 0x49e0, 0xa0, 0x4c, 0xc7, 0x30, 0x40, 0x6f, 0x79, 0x84};
