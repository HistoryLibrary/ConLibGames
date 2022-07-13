#define NEW_CONLIB_IMPLEMENTATION
#include "CONLIB.H"

int main()
{
    ConLibSetTitle(_T("NewConLib Example"));
    ConLibSetWinSize(30, 60);
    ConLibSetCursorLocation(2, 2);
    ConLibWriteString(_T("你好世界\n"));
    ConLibWriteChar(_T('H'));
#ifdef _DEBUG
    system("pause");
#endif
    return 0;
}