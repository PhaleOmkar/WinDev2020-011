#pragma once

class ISum:public IUnknown
{
	public:
		virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int*) = 0;
};

class ISubtract:public IUnknown
{
	public:
		virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*) = 0;
};

class IMultiplication:public IUnknown
{
	public:
		virtual HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*) = 0;
};

class IDivision:public IUnknown
{
	public:
		virtual HRESULT __stdcall DivisionOfTwoIntegers(int, int, int*) = 0;
};

// {DD266D5C-F6FE-42D9-A400-03C85A6150BF}
const CLSID CLSID_SumSubtract = {0xdd266d5c, 0xf6fe, 0x42d9, 0xa4, 0x0, 0x3, 0xc8, 0x5a, 0x61, 0x50, 0xbf};

// {E3636CFF-26AA-4C5A-89B1-19758D77E1F4}
const CLSID CLSID_MultiplicationDivision = {0xe3636cff, 0x26aa, 0x4c5a, 0x89, 0xb1, 0x19, 0x75, 0x8d, 0x77, 0xe1, 0xf4};

// {BA6DABD1-1F23-438F-863F-B47607695E36}
const IID IID_ISum = {0xba6dabd1, 0x1f23, 0x438f, 0x86, 0x3f, 0xb4, 0x76, 0x7, 0x69, 0x5e, 0x36};

// {42504100-2154-438B-85AD-BE6658C68115}
const IID IID_ISubtract = {0x42504100, 0x2154, 0x438b, 0x85, 0xad, 0xbe, 0x66, 0x58, 0xc6, 0x81, 0x15};

// {6C5A2554-17D5-4C6E-A625-420C536B0CD2}
const IID IID_IMultiplication = {0x6c5a2554, 0x17d5, 0x4c6e, 0xa6, 0x25, 0x42, 0xc, 0x53, 0x6b, 0xc, 0xd2};

// {6547104C-9A73-4BC0-AC72-8F2686F72FD6}
const IID IID_IDivision = {0x6547104c, 0x9a73, 0x4bc0, 0xac, 0x72, 0x8f, 0x26, 0x86, 0xf7, 0x2f, 0xd6};
