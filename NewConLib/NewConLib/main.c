﻿#define NEW_CONLIB_IMPLEMENTATION
#include "CONLIB.H"

int main()
{
    ConLibSetWinSize(30, 60);
    ConLibSetTitle(_T("NewConLib Example"));
    ConLibWriteString(_T("你好世界\n"));
    ConLibWriteChar(_T('H'));
    system("pause");
    return 0;
}