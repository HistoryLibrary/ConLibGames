
                     -=* ========================== *=-
                     -=* The ConLib Console Library *=-
                     -=* ========================== *=-

The ConLib library is a set of routines that offer simplified access to the
WIN32 API console manipulation functions.  All the programmer needs to do is
include the ConLib header file in any modules calling the ConLib functions,
and also make sure that the ConLib library is included in the list of files
the linker references.

==================================
Steps to using the ConLib library:
==================================

1) In any source code modules that use the library routines, you must be sure
   to include the ConLib header file, for example:

      #include    "ConLib.h"

   Make sure that the header file is either in the same subdirectory as your
   source code modules, or in the path the compiler searches for #include
   files.

2) The linker will need access to the ConLib library so your function calls
   can be resolved.  If you are working with a makefile, simply add it to the
   list of libraries.  If you are working in a Visual C++ project, do the
   following:

   a) Bring up the linker configuration dialog by traversing the menu path
      "Project -> Settings" and then clicking on the "Link" dialog tab.

   b) In the "Object/library modules" edit control, place your cursor at the
      end of the file list and add the appropriate ConLib filename (see the
      "Files.txt" file for details).

   c) The linker will need to locate the ConLib library file when you build
      your project.  The simplest way to achieve this is to place the
      appropriate ConLib library file in the same subdirectory where your
      source code files are located.  An alternate method is to place the
      library in the subdirectory of your own choosing, then updating the
      library path the linker searches (you can find this by traversing the
      menu path "Tools -> Options" and selecting "Library files" from the
      drop-down list control for directories).

That's all there is to it!  Happy coding!

Scott Edwards
sedwards@fullcoll.edu
02/11/2000
