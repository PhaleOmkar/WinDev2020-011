#pragma once

class ISum:public IUnknown
{
	public:
		virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int *) = 0; //Pure virtual function prototype
};

class ISubtract:public IUnknown
{
	public:
		virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int *) = 0; //Pure virtual function prototype
};

//CLSID of SumSubtract Component {0536A087-78D6-4497-983E-459BD206E3EB}
const CLSID CLSID_SumSubtract = {0x536a087, 0x78d6, 0x4497, 0x98, 0x3e, 0x45, 0x9b, 0xd2, 0x6, 0xe3, 0xeb};

//IID of ISum Interface {E2FC8473-99A7-41E4-AD0F-EC4DDE75F543}
const IID IID_ISum = {0xe2fc8473, 0x99a7, 0x41e4, 0xad, 0xf, 0xec, 0x4d, 0xde, 0x75, 0xf5, 0x43};

//IID of ISubtract Interface {B6364D61-2E08-49E0-A04C-C730406F7984}
const IID IID_ISubtract = {0xb6364d61, 0x2e08, 0x49e0, 0xa0, 0x4c, 0xc7, 0x30, 0x40, 0x6f, 0x79, 0x84};
