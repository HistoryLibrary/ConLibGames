// ============================================================================
// File: ConLib.h
// ============================================================================
// Programmer: Scott Edwards (December, 1999)
// ============================================================================
// This is a collection of routines that simplify the manipulation of the
// console under Visual C++.  It was developed using version 6 of the compiler.
// Note that these routines are platform-dependent, they are meant to be used
// on a Win95/Win98/WinNT system.
// ============================================================================

#ifndef CON_LIB_HEADER
#define CON_LIB_HEADER

#include    <windows.h>
#include    <wincon.h>
#include    <stdio.h>

// version information (this gets compiled into the .lib file so you can view
// it through an editor)
#define VER_MAJOR       "1"
#define VER_MINOR       "2.1"
#pragma comment(exestr, "ConLib Version " VER_MAJOR "." VER_MINOR)
#pragma comment(exestr, "Build date: " __DATE__ " at " __TIME__)
#ifdef  _MT
#pragma comment(exestr, "Multi-threaded library")
#else
#pragma comment(exestr, "Single-threaded library")
#endif  // _MT
#ifdef  _DEBUG
#pragma comment(exestr, "Debug Build")
#else
#pragma comment(exestr, "Non-Debug Build")
#endif  // _DEBUG

// define statements
#define NULL_CHAR               _T('\0')

// type definitions
enum    {
            INPUT_REC_MOUSE
            , INPUT_REC_KEYBOARD
            , INPUT_REC_WIN_BUFSIZE
            , INPUT_REC_MENU
            , INPUT_REC_FOCUS
            , INPUT_REC_UNKNOWN

        } CONLIB_INPUT_REC_TYPE;

enum    {
            LEFT_MOUSE_BUTTON_PRESSED
            , RIGHT_MOUSE_BUTTON_PRESSED
            , LEFT_MOUSE_BUTTON_DOUBLE_CLICKED
            , RIGHT_MOUSE_BUTTON_DOUBLE_CLICKED
            , NO_MOUSE_BUTTON_PRESSED
        };




#ifdef  __cplusplus
extern "C"
{
#endif  // __cplusplus

// function prototypes
BOOL    ConLibChangeScreenColor(WORD  foreground, WORD  background);
BOOL    ConLibDrawCol(TCHAR  outChar, int  numChars);
BOOL    ConLibDrawRow(TCHAR  outChar, int  numChars);
VOID    ConLibEnableDebugInfo(BOOL  bDisplayMessages, FILE*  filePtr);
BOOL    ConLibFillScreen(TCHAR  outChar);
BOOL    ConLibGetCursorLocation(int  *xCoordPtr, int  *yCoordPtr);
BOOL    ConLibGetMouseRecCoords(INPUT_RECORD  *recPtr, int  *xCoordPtr
                                                        , int  *yCoordPtr);
BOOL    ConLibGetTextColor(WORD  *consoleColor);
BOOL    ConLibGetWinSize(int  *numRowsPtr, int  *numColsPtr);
INT     ConLibMouseButtonPressed(INPUT_RECORD  *recPtr);
INT     ConLibReadInputRecord(INPUT_RECORD  *recPtr);
DWORD   ConLibReadString(TCHAR  *charBuf, DWORD  bufSize);
BOOL    ConLibSetCursorLocation(int  xCoord, int  yCoord);
BOOL    ConLibSetTextColor(WORD  foreground, WORD  background);
BOOL    ConLibSetTitle(TCHAR  *szTitle);
BOOL    ConLibSetWinSize(int  numRows, int  numCols);
BOOL    ConLibWriteChar(TCHAR  outChar);
BOOL    ConLibWriteString(TCHAR  *szString);

#ifdef  __cplusplus
}
#endif  // __cplusplus

#endif  // CON_LIB_HEADER





#if 0   // FUNCTION_DESCRIPTIONS

// Below is some more complete documentation on the functions listed above...


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
//                                      BACKGROUND_INTENSITY
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
// Note that the direction the column is drawn is from top to bottom.
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
// Note that the direction the row is drawn is from left to right.
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



// ==== ConLibEnableDebugInfo =================================================
//
// This function allows the caller to turn the display of messages written to
// the output stream on or off.  This function is only useful for displaying
// internal debug messages that are particular to the ConLib library (i.e.,
// when a ConLib function fails); if a ConLib function fails, then this
// function allows any ConLib error messages to be viewed on an output stream.
//
// Input:
//      bDisplayMessages    -- a value of TRUE will turn the display of stderr
//                             messages on, FALSE will turn them off
//
//      filePtr             -- a FILE pointer to an output stream; if NULL is
//                             passed, the stderr stream will be used by
//                             default
//
// Output:
//      Nothing.
//
// ============================================================================

VOID    ConLibEnableDebugInfo(BOOL  bDisplayMessages, FILE*  filePtr);



// ==== ConLibFillScreen ======================================================
//
// This function fills the current screen buffer with the character specified
// in the formal parameter.  If a null character (zero) is received in the
// formal parameter, a blank space is used by default as the display character.
//
// Input:
//      outChar     -- the character to fill the screen with.
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibFillScreen(TCHAR  outChar);



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



// ==== ConLibGetMouseRecCoords ===============================================
//
// This function extracts the X and Y coordinates of the mouse input record and
// copies them over to the corresponding formal parameters.
//
// Input:
//      recPtr      -- a pointer to an INPUT_RECORD
//
//      xCoordPtr   -- a pointer to an integer that will contain the "X"
//                     coordinate of the mouse input record
//
//      yCoordPtr   -- a pointer to an integer that will contain the "Y"
//                     coordinate of the mouse input record
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibGetMouseRecCoords(INPUT_RECORD  *recPtr, int  *xCoordPtr
                                                        , int  *yCoordPtr);



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



// ==== ConLibGetWinSize ======================================================
//
// This function fetches the current size of the console window.  The values
// are copied to whatever the pointer parameters are pointing to.
//
// Input:
//      szString    -- the string to display
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibGetWinSize(int  *numRowsPtr, int  *numColsPtr);



// ==== ConLibMouseButtonPressed ==============================================
//
// This function inspects the INPUT_RECORD parameter and determines if the
// either the left or right mouse button was pressed.
//
// Input:
//      recPtr      -- a pointer to an INPUT_RECORD
//
// Output:
//      An enumerated value indicating which mouse button was pressed.
//      possible values are:
//
//          LEFT_MOUSE_BUTTON_PRESSED           -- the left mouse button was
//                                                 pressed once
//
//          RIGHT_MOUSE_BUTTON_PRESSED          -- the right mouse button was
//                                                 pressed once
//
//          LEFT_MOUSE_BUTTON_DOUBLE_CLICKED    -- the left mouse button was
//                                                 double-clicked
//
//          RIGHT_MOUSE_BUTTON_DOUBLE_CLICKED   -- the right mouse button was
//                                                 double-clicked
//
//          NO_MOUSE_BUTTON_PRESSED             -- neither the left or right
//                                                 mouse button was pressed
//
// ============================================================================

INT     ConLibMouseButtonPressed(INPUT_RECORD  *recPtr);



// ==== ConLibReadInputRecord =================================================
//
// This function reads an input record from the current console's input buffer,
// which removes the record from the input buffer.  Note that this function
// will block the calling thread -- program flow will not return to the caller
// until an input record is retrieved from the current console's input buffer.
//
// Input:
//      recPtr  -- a pointer to an INPUT_RECORD structure; if this function is
//                 successful, the caller's structure will be initialized with
//                 data values particular to the record type (see the VC++
//                 documentation on "INPUT_RECORD" for details)
//
// Output:
//      An enumerated value indicating the type of record that was read.  The
//      possible values are:
//
//          INPUT_REC_MOUSE             -- a mouse movement or button click was
//                                         read
//
//          INPUT_REC_KEYBOARD          -- a keyboard event was read
//
//          INPUT_REC_WIN_BUFSIZE       -- the console screen buffer size was
//                                         changed
//
//          INPUT_REC_MENU              -- a menu event was read; these events
//                                         are used internally by the system
//                                         and should be ignored
//
//          INPUT_REC_FOCUS             -- a focus event was read; these events
//                                         are used internally by the system
//                                         and should be ignored
//
//          INPUT_REC_UNKNOWN           -- the input record type was not
//                                         recognized
//
// ============================================================================

INT     ConLibReadInputRecord(INPUT_RECORD  *recPtr);



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
//      If an error occurs, an invalid value is returned (-1); else, the total
//      number of characters read is returned (not counting the null character)
//
// ============================================================================

DWORD   ConLibReadString(TCHAR  *charBuf, DWORD  bufSize);



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
//                                      BACKGROUND_INTENSITY
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
//      numRows     -- the target number of rows for the new window (one-based)
//
//      numCols     -- the target number of columns for the new window
//                     (one-based)
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



// ==== ConLibWriteDebugMessage ===============================================
//
// This function writes a null-terminated string to the debug output stream if
// the global variable "g_displayDebugInfo" is set to a non-zero value.  This
// global variable is static to the ConLib.c module, and can be set or cleared
// by calling the "ConLibEnableDebugInfo" function (same goes for the debug
// output stream).
//
// Input:
//      szMessage   -- a null-terminated string containing the message to write
//                     to the stderr stream
//
// Output:
//      Nothing.
//
// ============================================================================

static  VOID    ConLibWriteDebugMessage(TCHAR  *szMessage);



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



#endif  // FUNCTION_DESCRIPTIONS