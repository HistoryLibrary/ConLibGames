﻿#define NEW_CONLIB_IMPLEMENTATION
#include "CONLIB.H"

#define READ_BUF_SIZE 256

int main()
{
    ConLibSetTitle(_T("NewConLib Example"));
    ConLibSetWinSize(30, 60);
    ConLibSetCursorLocation(2, 2);
    ConLibSetTextColor(FOREGROUND_RED, BACKGROUND_GREEN);
    ConLibWriteString(_T("你好世界\n"));
    ConLibWriteChar(_T('H'));
    TCHAR readBuf[READ_BUF_SIZE];
    int read = ConLibReadString(readBuf, READ_BUF_SIZE);
#ifdef _DEBUG
    system("pause");
#endif
    return 0;
}