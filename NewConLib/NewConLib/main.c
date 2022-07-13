#define NEW_CONLIB_IMPLEMENTATION
#include "CONLIB.H"

#define READ_BUF_SIZE 256

int main()
{
    ConLibSetTitle(_T("NewConLib Example"));
    ConLibSetWinSize(30, 60);
    ConLibSetCursorLocation(4, 2);
    int cursorPosX, cursorPosY;
    ConLibGetCursorLocation(&cursorPosX, &cursorPosY);
    ConLibSetTextColor(FOREGROUND_RED, BACKGROUND_GREEN);
    ConLibWriteString(_T("你好世界\n"));
    ConLibWriteChar(_T('H'));
    WORD att;
    ConLibGetTextColor(&att);
    TCHAR readBuf[READ_BUF_SIZE];
    int read = ConLibReadString(readBuf, READ_BUF_SIZE);
    ConLibChangeScreenColor(FOREGROUND_RED, BACKGROUND_BLUE);
    ConLibFillScreen(_T('s'));
#ifdef _DEBUG
    system("pause");
#endif
    return 0;
}