#pragma once

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

// {E3636CFF-26AA-4C5A-89B1-19758D77E1F4}
const CLSID CLSID_MultiplicationDivision = {0xe3636cff, 0x26aa, 0x4c5a, 0x89, 0xb1, 0x19, 0x75, 0x8d, 0x77, 0xe1, 0xf4};

// {FC329C11-0D00-4CF0-8FD3-68A3F996B505}
const IID IID_IMultiplication = {0xfc329c11, 0xd00, 0x4cf0, 0x8f, 0xd3, 0x68, 0xa3, 0xf9, 0x96, 0xb5, 0x05};

// {6BA3A089-E1AB-4B2E-8A70-154657AFF813}
const IID IID_IDivision = {0x6ba3a089, 0xe1ab, 0x4b2e, 0x8a, 0x70, 0x15, 0x46, 0x57, 0xaf, 0xf8, 0x13};
