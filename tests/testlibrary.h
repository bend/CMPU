/**
 *
 *       @file  testlibrary.h
 *
 *      @brief 	Testing class for LibraryManager
 *
 *    @version  1.0
 *       @date  03.07.2011 10:05:11
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef _TEST_LIBRARY_H_
#define _TEST_LIBRARY_H_
#include <iostream>
using namespace std;

#include <assert.h>

#include <library/librarymanager.h>
#include <defines/defines.h>
#include <utils/utils.h>

class TestLibrary:public LibraryManager{

	public:
		TestLibrary(string lib);
};

#endif
