#pragma once
#include "help_ex.h"

EX_DEFINE_API(RtlGetNtVersionNumbers, int, (int*, int*, int*));


void ����NTDLL();
int ȡϵͳ���汾��(int* dwMinor=0, int* Optional=0);
