#include "Ntdll_ex.h"

EX_DECLEAR_API(RtlGetNtVersionNumbers);


void ����NTDLL()
{
	HMODULE hModule = LoadLibraryW(L"ntdll.dll");
	if (hModule)
	{
		EX_GET_API(RtlGetNtVersionNumbers);

	}
}


int ȡϵͳ���汾��(int& dwMinor, int& Optional)
{
	int dwMajor = 0;
	RtlGetNtVersionNumbers(&dwMajor, &dwMinor, &Optional);
	return dwMajor;
}