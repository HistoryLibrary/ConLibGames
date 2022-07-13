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
#include    <tchar.h>
#include    <stdio.h>

// version information (this gets compiled into the .lib file so you can view
// it through an editor)
#define VER_MAJOR       "2"
#define VER_MINOR       "0"
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
#define ALT_HANDLE              1
#define STD_HANDLE              0


// type definitions
enum    {
        INPUT_REC_MOUSE
        , INPUT_REC_KEYBOARD
        , INPUT_REC_WIN_BUFSIZE
        , INPUT_REC_MENU
        , INPUT_REC_FOCUS
        , INPUT_REC_UNKNOWN
        };

enum    {
        LEFT_MOUSE_BUTTON_PRESSED
        , RIGHT_MOUSE_BUTTON_PRESSED
        , LEFT_MOUSE_BUTTON_DOUBLE_CLICKED
        , RIGHT_MOUSE_BUTTON_DOUBLE_CLICKED
        , NO_MOUSE_BUTTON_PRESSED
        };


// macros
#define ConLibCheckMouseButtonStateFlag(recPtr, flag)                         \
                        ((recPtr)->Event.MouseEvent.dwButtonState & (flag))
#define ConLibCheckMouseControlKeyStateFlag(recPtr, flag)                     \
                        ((recPtr)->Event.MouseEvent.dwControlKeyState & (flag))
#define ConLibCheckMouseEventFlag(recPtr, flag)                               \
                        ((recPtr)->Event.MouseEvent.dwEventFlags & (flag))


#ifdef  __cplusplus
extern "C"
{
#endif  // __cplusplus

// function prototypes
BOOL    ConLibCopyBufferToScreen(int  xCoord, int  yCoord, int  width
                                                        , int  height
                                                        , CHAR_INFO  *bufPtr);
BOOL    ConLibCopyScreenToBuffer(int  xCoord, int  yCoord, int  width
                                                        , int  height
                                                        , CHAR_INFO  *bufPtr);
BOOL    ConLibDrawCol(TCHAR  outChar, int  numChars);
BOOL    ConLibDrawRow(TCHAR  outChar, int  numChars);
VOID    ConLibEnableDebugInfo(BOOL  bDisplayMessages, FILE*  filePtr);
BOOL    ConLibFillScreen(TCHAR  outChar);
BOOL    ConLibGetCursorLocation(int  *xCoordPtr, int  *yCoordPtr);
INT     ConLibGetEventType(INPUT_RECORD  *recPtr);
BOOL    ConLibGetMouseRecCoords(INPUT_RECORD  *recPtr, int  *xCoordPtr
                                                        , int  *yCoordPtr);
BOOL    ConLibGetTextColor(WORD  *foreColorPtr, WORD  *backColorPtr);
BOOL    ConLibGetWinSize(int  *numRowsPtr, int  *numColsPtr);
BOOL    ConLibInitialize(int  numRows, int  numCols);
INT     ConLibMouseButtonPressed(INPUT_RECORD  *recPtr);
VOID    ConLibPauseDisplay(BOOL  bPauseDisplay);
INT     ConLibReadInputRecord(INPUT_RECORD  *recPtr);
DWORD   ConLibReadString(TCHAR  *charBuf, DWORD  bufSize);
BOOL    ConLibSetCursorLocation(int  xCoord, int  yCoord);
BOOL    ConLibSetScreenColor(WORD  foreground, WORD  background);
BOOL    ConLibSetTextColor(WORD  foreground, WORD  background);
BOOL    ConLibSetTitle(TCHAR  *szTitle);
BOOL    ConLibSetWinSize(int  numRows, int  numCols);
BOOL    ConLibWriteChar(const TCHAR  outChar);
BOOL    ConLibWriteString(const TCHAR  *szString);

#ifdef  __cplusplus
}
#endif  // __cplusplus

#endif  // CON_LIB_HEADER





#if 0   // FUNCTION_DESCRIPTIONS

// Below is some more complete documentation on the macros and functions
// listed above...




// ==== ConLibCheckMouseButtonStateFlag =======================================
//
// This macro allows the caller to test the "pressed" state of a mouse button
// in an INPUT_RECORD of type MOUSE_EVENT.  For instance, to see if the left
// mouse button was pressed in a mouse event record, you'd write:
//
//      if (ConLibCheckMouseButtonStateFlag(&inputRec
//                                      , FROM_LEFT_1ST_BUTTON_PRESSED))
//          {
//          // left mouse button was pressed...
//          }
//
//
// Input:
//      recPtr      -- a pointer to an INPUT_RECORD of type MOUSE_EVENT
//
//      flag        -- a flag value defined by Microsoft; the following values
//                     are available:
//
//                     *) FROM_LEFT_1ST_BUTTON_PRESSED
//                     *) RIGHTMOST_BUTTON_PRESSED
//                     *) FROM_LEFT_2ND_BUTTON_PRESSED
//                     *) FROM_LEFT_3RD_BUTTON_PRESSED
//                     *) FROM_LEFT_4TH_BUTTON_PRESSED
//
// Output:
//      A nonzero value if the "flag" button is in a "pressed" state; zero
//      otherwise.
//
// ============================================================================

INT     ConLibCheckMouseButtonStateFlag(INPUT_RECORD  *recPtr, INT  flag);



// ==== ConLibCheckMouseControlKeyStateFlag ===================================
//
// This macro allows the caller to test the "pressed" state of certain keys
// in an INPUT_RECORD of type MOUSE_EVENT.  For instance, to see if the left
// Ctrl key was pressed during the mouse event record, you could write:
//
//      if (ConLibCheckMouseControlKeyStateFlag(&inputRec, LEFT_CTRL_PRESSED))
//          {
//          // the left control key was pressed...
//          }
//
//
// Input:
//      recPtr      -- a pointer to an INPUT_RECORD of type MOUSE_EVENT
//
//      flag        -- a flag value defined by Microsoft; the following values
//                     are available:
//
//                     *) RIGHT_ALT_PRESSED means the right alt key is pressed
//                     *) LEFT_ALT_PRESSED means the left alt key is pressed
//                     *) RIGHT_CTRL_PRESSED means right ctrl key is pressed
//                     *) LEFT_CTRL_PRESSED means the left ctrl key is pressed
//                     *) CAPSLOCK_ON means the caps lock light is on
//                     *) ENHANCED_KEY means the key is enhanced
//                     *) NUMLOCK_ON means the num lock light is on
//                     *) SCROLLLOCK_ON means the scroll lock light is on
//                     *) SHIFT_PRESSED means the shift key is pressed
//
// Output:
//      A nonzero value if the "flag" values are in a "pressed" state; zero
//      otherwise.
//
// ============================================================================

INT     ConLibCheckMouseControlKeyStateFlag(INPUT_RECORD  *recPtr, INT  flag);



// ==== ConLibCheckMouseEventFlag =============================================
//
// This macro allows the caller to test the type of mouse event record.  For
// instance, to see if the current INPUT_RECORD indicates that the mouse has
// been moved, you could write:
//
//      if (ConLibCheckMouseEventFlag(&inputRec, MOUSE_MOVED))
//          {
//          // the mouse was moved...
//          }
//
//
// NOTE: Another helpful function to aid in processing single or double click
//       mouse button events is the ConLibMouseButtonPressed function.
//
//
// Input:
//      recPtr      -- a pointer to an INPUT_RECORD of type MOUSE_EVENT
//
//      flag        -- a flag value defined by Microsoft; the following values
//                     are available:
//
//                     *) DOUBLE_CLICK means the second click of a double-click
//                        event occurred (the first click is processed as a
//                        regular mouse button-press event)
//                     *) MOUSE_MOVED means a change in mouse position occurred
//                     *) MOUSE_WHEELED means the mouse wheel was rolled
//
// Output:
//      A nonzero value if the "flag" values are in a "pressed" state; zero
//      otherwise.
//
// ============================================================================

INT     ConLibCheckMouseEventFlag(INPUT_RECORD  *recPtr, INT  flag);



// ==== ConLibCopyBufferToScreen ==============================================
//
// This function allows the caller to write a stored buffer of screen data to
// the console output window.  Typically the buffer information is data that
// was extracted through a call to the ConLibCopyScreenToBuffer function.
//
// Input:
//      xCoord  -- the X coordinate of the upper-left corner of the region to
//                 to write to the screen
//
//      yCoord  -- the Y coordinate of the upper-left corner of the region to
//                 to write to the screen
//
//      width   -- the number of columns to write
//
//      height -- the number of rows to write
//
//      bufPtr  -- a pointer to a CHAR_INFO buffer that contains the data to be
//                 written to the output console window ((see the online VC
//                 help for details regarding this structure)
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibCopyBufferToScreen(int  xCoord, int  yCoord, int  width
                                                        , int  height
                                                        , CHAR_INFO  *bufPtr)



// ==== ConLibCopyScreenToBuffer ==============================================
//
// This function allows the caller to copy a region of the console screen to a
// memory buffer.  Thus the caller can set aside portions of a screen and
// restore them later with the ConLibCopyBufferToScreen function.
//
// NOTE: it is assumed that the caller has properly allocated the "bufPtr"
//       parameter and that the size of that buffer is reflected in the "width"
//       and "height" parameters.
//
// Input:
//      xCoord  -- the X coordinate of the upper-left corner of the region to
//                 to read from the screen
//
//      yCoord  -- the Y coordinate of the upper-left corner of the region to
//                 to read from the screen
//
//      width   -- the number of columns to read
//
//      height -- the number of rows to read
//
//      bufPtr  -- a pointer to a CHAR_INFO buffer that will store the data
//                 extracted from the console window (see the online VC help
//                 for details regarding this structure)
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibCopyScreenToBuffer(int  xCoord, int  yCoord, int  width
                                                        , int  height
                                                        , CHAR_INFO  *bufPtr)



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

BOOL    ConLibDrawCol(TCHAR  outChar, int  numChars)



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

BOOL    ConLibDrawRow(TCHAR  outChar, int  numChars)



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

VOID    ConLibEnableDebugInfo(BOOL  bDisplayMessages, FILE*  filePtr)



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

BOOL    ConLibFillScreen(TCHAR  outChar)



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

BOOL    ConLibGetCursorLocation(int  *xCoordPtr, int  *yCoordPtr)



// ==== ConLibGetEventType ====================================================
//
// This function inspects an input record and returns the record's "type".
//
// Input:
//      recPtr  -- a pointer to an INPUT_RECORD structure; it is assumed that
//                 the record contains a valid input record (see the VC++
//                 documentation on "INPUT_RECORD" for details).
//
// Output:
//      An enumerated value indicating the type of record contained in the
//      input structure.  The possible values are:
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

INT     ConLibGetEventType(INPUT_RECORD  *recPtr)



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
                                                        , int  *yCoordPtr)



// ==== ConLibGetTextColor ====================================================
//
// This function gets the current color attributes for characters drawn to the
// screen.
//
// Input:
//      foreColorPtr    -- a pointer to a WORD that will store the current text
//                         foreground color
//      
//      backColorPtr    -- a pointer to a WORD that will store the current text
//                         background color
//      
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibGetTextColor(WORD  *foreColorPtr, WORD  *backColorPtr)



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

BOOL    ConLibGetWinSize(int  *numRowsPtr, int  *numColsPtr)



// ==== ConLibInitialize ======================================================
//
// This function is responsible for initializing the ConLib library.  It
// allocates and initializes screen buffers and static global variables.
//
// NOTE: Any client of the ConLib library should call this function first.
//
// Input:
//      numRows     -- the desired number of rows for the console window
//
//      numCols     -- the desired number of columns for the console window
//
// Output:
//      A value of TRUE if all goes well, FALSE if not.
//
// ============================================================================

BOOL    ConLibInitialize(int  numRows, int  numCols)



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

INT     ConLibMouseButtonPressed(INPUT_RECORD  *recPtr)



// ==== ConLibPauseDisplay ====================================================
//
// This function buffers anything written to the console output screen.  The
// caller can thus pause the output temporarily, write complex output to the
// screen, then instantly  refresh the display by calling this function again.
//
// Input:
//      bPauseDisplay   -- a boolean value indicating whether or not subsequent
//                         ConLib functions should immediately write their
//                         output to the screen or not; a value of TRUE means
//                         all screen output is to be stored in memory, while a
//                         value of FALSE means whatever has been written to
//                         memory is to be immediately flushed to the output
//                         screen.
//
// Output:
//      Nothing.
//
// ============================================================================

VOID    ConLibPauseDisplay(BOOL  bPauseDisplay)



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
//      The type of input record as determined by the ConLibGetEventType
//      function.  If this function fails to successfully read an input record,
//      a record type "unknown" is returned to the caller.
//
// ============================================================================

INT     ConLibReadInputRecord(INPUT_RECORD  *recPtr)



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

DWORD   ConLibReadString(TCHAR  *charBuf, DWORD  bufSize)



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

BOOL    ConLibSetCursorLocation(int  xCoord, int  yCoord)



// ==== ConLibSetScreenColor ==================================================
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

BOOL    ConLibSetScreenColor(WORD  foreground, WORD  background)



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

BOOL    ConLibSetTextColor(WORD  foreground, WORD  background)



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

BOOL    ConLibSetTitle(TCHAR  *szTitle)



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

BOOL    ConLibSetWinSize(int  numRows, int  numCols)



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

BOOL    ConLibWriteChar(const TCHAR  outChar)



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

BOOL    ConLibWriteString(const TCHAR  *szString)


#endif  // FUNCTION_DESCRIPTIONS
