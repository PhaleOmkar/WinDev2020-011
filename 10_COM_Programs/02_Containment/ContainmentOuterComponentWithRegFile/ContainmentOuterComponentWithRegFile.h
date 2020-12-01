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

// {DD266D5C-F6FE-42D9-A400-03C85A6150BF}
const CLSID CLSID_SumSubtract= 
{0xdd266d5c, 0xf6fe, 0x42d9, 0xa4, 0x0, 0x3, 0xc8, 0x5a, 0x61, 0x50, 0xbf};

// {BA6DABD1-1F23-438F-863F-B47607695E36}
const IID IID_ISum = 
{0xba6dabd1, 0x1f23, 0x438f, 0x86, 0x3f, 0xb4, 0x76, 0x7, 0x69, 0x5e, 0x36};

// {42504100-2154-438B-85AD-BE6658C68115}
const IID IID_ISubtract = 
{0x42504100, 0x2154, 0x438b, 0x85, 0xad, 0xbe, 0x66, 0x58, 0xc6, 0x81, 0x15};