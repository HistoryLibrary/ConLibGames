// ============================================================================
// File: ConLib.c (v1.0)
// ============================================================================
// Programmer: Scott Edwards (December, 1999)
// ============================================================================
// This is a collection of routines that simplify the manipulation of the
// console under Visual C++.  It was developed using version 6 of the compiler.
// Note that these routines are completely platform-dependent, they are meant
// to be used on a Win95/Win98/WinNT system.
// ============================================================================

// NewConLib version : 1.0
// Programmer : MingZhao Wu
// Edit time : 2022/7/13 10:50 AM
// usage:
// #define NEW_CONLIB_IMPLEMENTATION //note: define this macro once!
// #include "CONLIB.H"

#ifndef CON_LIB_HEADER
#define CON_LIB_HEADER

#include    <windows.h>
#include    <wincon.h>

// define statements
#define NULL_CHAR               _T('\0')

#ifdef  __cplusplus
extern "C"
{
#endif  // __cplusplus

// function prototypes
BOOL    ConLibChangeScreenColor(WORD  foreground, WORD  background);
BOOL    ConLibDrawCol(TCHAR  outChar, int  numChars);
BOOL    ConLibDrawRow(TCHAR  outChar, int  numChars);
BOOL    ConLibFillScreen(TCHAR  outChar);
BOOL    ConLibGetTextColor(WORD  *consoleColor);
BOOL    ConLibGetCursorLocation(int  *xCoordPtr, int  *yCoordPtr);
DWORD   ConLibReadString(TCHAR  *charBuf, DWORD  bufSize);
BOOL    ConLibSetTextColor(WORD  foreground, WORD  background);
BOOL    ConLibSetCursorLocation(int  xCoord, int  yCoord);
BOOL    ConLibSetTitle(TCHAR  *szTitle);
BOOL    ConLibSetWinSize(int  numRows, int  numCols);
BOOL    ConLibWriteChar(TCHAR  outChar);
BOOL    ConLibWriteString(TCHAR  *szString);

#ifdef  __cplusplus
}
#endif  // __cplusplus

#endif  // CON_LIB_HEADER






#if 0

// "readme" stuff...
// ==== ConLibChangeScreenColor ===============================================
//
// This function changes the foreground and background colors of the current
// console, using the specified foreground and background colors.
//
// The foreground color options are:    FOREGROUND_BLUE
//                                      FOREGROUND_GREEN
//                                      FOREGROUND_RED
//                                      FOREGROUND_INTENSITY
//
// The background color options are:    BACKGROUND_BLUE
//                                      BACKGROUND_GREEN
//                                      BACKGROUND_RED
//                                      BACKGROUND_INTENSITY.
//
// Any combination of the above values can be specified.
//
//
// Input:
//      foreground  -- a WORD value representing a foreground color
//
//      background  -- a WORD value representing a background color
//
// Output:
//      Nothing.
//
// ============================================================================

BOOL    ConLibChangeScreenColor(WORD  foreground, WORD  background);



// ==== ConLibDrawCol =========================================================
//
// This function draws a column of characters to the current screen buffer.
// The caller may specify a single character to draw, and the number of times
// the character is to be drawn.  (This is helpful in drawing vertical lines.)
//
// Input:
//      outChar     -- the character to draw to the screen
//
//      numChars    -- the number of times the character is to be drawn
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibDrawCol(TCHAR  outChar, int  numChars);



// ==== ConLibDrawRow =========================================================
//
// This function draws a row of characters to the current screen buffer.  The
// caller may specify a single character to draw, and the number of times the
// character is to be drawn.  (This is helpful in drawing horizontal lines.)
//
// Input:
//      outChar     -- the character to draw to the screen
//
//      numChars    -- the number of times the character is to be drawn
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibDrawRow(TCHAR  outChar, int  numChars);



// ==== ConLibFillScreen ======================================================
//
// This function fills the current screen buffer with the character specified
// in the formal parameter.
//
// Input:
//      outChar     -- the character to fill the screen with.
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibFillScreen(TCHAR  outChar);



// ==== ConLibGetTextColor ====================================================
//
// This function gets the current color attributes for characters drawn to the
// screen.
//
// Input:
//      consoleColor    -- a pointer to a WORD that stores the current text
//                         attributes for the console; the low-order byte
//                         contains the background color, and the high-order
//                         byte contains the foreground color.
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibGetTextColor(WORD  *consoleColor);



// ==== ConLibGetCursorLocation ===============================================
//
// This function determines the current position of the cursor in the console
// screen buffer.  The upper left corner is the origin (0, 0), and positive 'x'
// and 'y' coordinates specify locations further right and down respectively.
//
// Input:
//      xCoordPtr   -- a pointer to an int that will store the 'x' coordinate
//
//      yCoordPtr   -- a pointer to an int that will store the 'y' coordinate
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibGetCursorLocation(int  *xCoordPtr, int  *yCoordPtr);



// ==== ConLibReadString ======================================================
//
// This function reads a string of text from the keyboard (which are really
// keystrokes entered into the console's input buffer).  This function returns
// the total number of characters read, not counting the null character.
//
// Input:
//      charBuf     -- the address of the buffer that will store the characters
//
//      bufSize     -- the size of the destination buffer
//
// Output:
//      The total number of characters read, not counting the null character.
//
// ============================================================================

DWORD   ConLibReadString(TCHAR  *charBuf, DWORD  bufSize);



// ==== ConLibSetTextColor ====================================================
//
// This function sets the color attributes for any characters drawn to the
// screen.  Note that only characters drawn AFTER this function completes are
// affected.
//
// The foreground color options are:    FOREGROUND_BLUE
//                                      FOREGROUND_GREEN
//                                      FOREGROUND_RED
//                                      FOREGROUND_INTENSITY
//
// The background color options are:    BACKGROUND_BLUE
//                                      BACKGROUND_GREEN
//                                      BACKGROUND_RED
//                                      BACKGROUND_INTENSITY.
//
// Any combination of the above values can be specified.
//
//
// Input:
//      foreground  -- the foreground value
//
//      background  -- the background value
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================


BOOL    ConLibSetTextColor(WORD  foreground, WORD  background);



// ==== ConLibSetCursorLocation ===============================================
//
// This function positions the cursor specified by the formal parameters.
//
// Input:
//      xCoord      -- the "X" coordinate in the current screen buffer
//
//      yCoord      -- the "Y" coordinate in the current screen buffer
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibSetCursorLocation(int  xCoord, int  yCoord);



// ==== ConLibSetTitle ========================================================
//
// This function sets the title for the console window.  It's simply a wrapper
// for a call to the corresponding Win32 API.
//
// Input:
//      szTitle     -- a null-terminated string
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibSetTitle(TCHAR  *szTitle);



// ==== ConLibSetWinSize ======================================================
//
// This function resizes the current console window and screen buffer to the
// size specified by the formal parameters.
//
// Input:
//      numRows     -- the target number of rows for the new window
//
//      numCols     -- the target number of columns for the new window
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibSetWinSize(int  numRows, int  numCols);



// ==== ConLibWriteChar =======================================================
//
// This function writes a single character to the current screen buffer.  It is
// assumed that the caller has already positioned the cursor to the target
// location before calling this function.
//
// Input:
//      outChar     -- the character to write to the screen
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibWriteChar(TCHAR  outChar);



// ==== ConLibWriteString =====================================================
//
// This function writes a null-terminated string to the current screen buffer.
// It is assumed that the caller has already positioned the cursor to the
// desired location.
//
// Input:
//      szString    -- the string to display
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibWriteString(TCHAR  *szString);

#endif  // 0






#ifdef NEW_CONLIB_IMPLEMENTATION

#ifdef UNICODE
#define STR_LEN(s) (wcslen(s))
#else
#define STR_LEN(s) (strlen(s))
#endif

#ifndef _T
#define _T(x) L##x
#endif

#ifndef ALLOC
#define ALLOC(type, n) ((type*)malloc((n) * sizeof(type)))
#endif

BOOL    ConLibChangeScreenColor(WORD  foreground, WORD  background)
{
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    BOOL ret_buf = GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);
    if (!ret_buf) return FALSE;

    COORD coord;
    coord.X = 0;
    coord.Y = 0;

    DWORD written;

    BOOL ret = FillConsoleOutputAttribute(hConsoleOutput, foreground | background, csbi.dwSize.X * csbi.dwSize.Y, coord, &written);
    return ret;
}

BOOL    ConLibDrawCol(TCHAR  outChar, int  numChars)
{
    int cursorX, cursorY;
    BOOL ret_cur = ConLibGetCursorLocation(&cursorX, &cursorY);
    if (!ret_cur) return FALSE;

    BOOL ret = TRUE;

    for (int i = 0; i < numChars; i++)
    {
        BOOL ret_write = ConLibWriteChar(outChar);
        if (!ret_write) return FALSE;
        ret |= ret_write;
        
        if (i < numChars - 1)
        {
            BOOL ret_set = ConLibSetCursorLocation(cursorX, ++cursorY);
            if (!ret_set) return FALSE;
            ret |= ret_set;
        }
    }

    return ret;
}

BOOL    ConLibDrawRow(TCHAR  outChar, int  numChars)
{
    TCHAR* buf = ALLOC(TCHAR, numChars + 1);
    if (buf == NULL) return FALSE;

    for (int i = 0; i < numChars; i++)
    {
        buf[i] = outChar;
    }
    buf[numChars] = 0;

    BOOL ret = ConLibWriteString(buf);
    free(buf);
    return ret;
}

BOOL    ConLibFillScreen(TCHAR  outChar)
{
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    BOOL ret_buf = GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);
    if (!ret_buf) return FALSE;

    COORD coord;
    coord.X = 0;
    coord.Y = 0;

    DWORD written;

    BOOL ret = FillConsoleOutputCharacter(hConsoleOutput, outChar, csbi.dwSize.X * csbi.dwSize.Y, coord, &written);
    return ret;
}

BOOL    ConLibGetTextColor(WORD* consoleColor)
{
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    BOOL ret = GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);
    if (ret)
    {
        *consoleColor = csbi.wAttributes;
    }
    return ret;
}

BOOL    ConLibGetCursorLocation(int* xCoordPtr, int* yCoordPtr)
{
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    BOOL ret = GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);
    if (ret)
    {
        *xCoordPtr = csbi.dwCursorPosition.X;
        *yCoordPtr = csbi.dwCursorPosition.Y;
    }
    return ret;
}

DWORD   ConLibReadString(TCHAR* charBuf, DWORD  bufSize)
{
    HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD read;
    DWORD  nNumberOfCharsToRead = bufSize / sizeof(TCHAR);
    BOOL ret = ReadConsole(hConsoleInput, charBuf, nNumberOfCharsToRead, &read, NULL);
    if (ret)
    {
        return read;
    }
    else
    {
        return 0;
    }
}

BOOL    ConLibSetTextColor(WORD  foreground, WORD  background)
{
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    return SetConsoleTextAttribute(hConsoleOutput, foreground | background);
}

BOOL    ConLibSetCursorLocation(int  xCoord, int  yCoord)
{
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = xCoord;
    coord.Y = yCoord;
    return SetConsoleCursorPosition(hConsoleOutput, coord);
}

BOOL    ConLibSetTitle(TCHAR* szTitle)
{
    return SetConsoleTitle(szTitle);
}

BOOL    ConLibSetWinSize(int  numRows, int  numCols)
{
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

#ifndef DONT_FIX_SET_WIN_SIZE_BUG
    SMALL_RECT sm1;
    sm1.Left = 0;
    sm1.Top = 0;
    sm1.Right = 1;
    sm1.Bottom = 1;
    BOOL ret_win1 = SetConsoleWindowInfo(hConsoleOutput, TRUE, &sm1);
#endif

    COORD coord;
    coord.X = numCols;
    coord.Y = numRows;
    BOOL ret_buf = SetConsoleScreenBufferSize(hConsoleOutput, coord);

    SMALL_RECT sm;
    sm.Left = 0;
    sm.Top = 0;
    sm.Right = numCols - 1;
    sm.Bottom = numRows - 1;
    BOOL ret_win = SetConsoleWindowInfo(hConsoleOutput, TRUE, &sm);

    return ret_buf && ret_win;
}

BOOL    ConLibWriteChar(TCHAR  outChar)
{
    TCHAR szString[2];
    szString[0] = outChar;
    szString[1] = 0;
    return ConLibWriteString(szString);
}

BOOL    ConLibWriteString(TCHAR* szString)
{
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    size_t len = STR_LEN(szString);
    DWORD written;
    BOOL ret = WriteConsole(hConsoleOutput, szString, len, &written, NULL);
    return ret;
}

#endif