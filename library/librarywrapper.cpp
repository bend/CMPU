/**
 *
 *       @file  librarywrapper.cpp
 *
 *      @brief  A wrapper to the library hidding insertion difficulties
 *      		It automatically creates an author, genre, ... 
 *      		if not already existing in the library
 *
 *    @version  1.0
 *       @date  03.07.2011 14:41:44
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#ifndef _LIBRARY_WRAPPER_H_
#define _LIBRARY_WRAPPER_H_
#include <library/librarymanager.h>

class LibraryWrapper:public LibraryManager{
	public:
		LibraryWrapper(string lib);
		/*TODO*/



};

#endif
