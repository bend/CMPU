/**
 *
 *       @file  librarymanager.cpp
 *
 *      @brief  Wrapper around music library
 *
 *    @version  1.0
 *       @date  18.06.2011 19:02:58
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <librarymanager.h>

LibraryManager::LibraryManager(string libname){
	this->libname=libname;
	this->adapter = new SqliteAdapter();
}

int LibraryManager::createLibrary(){
	adapter->openDatabase(libname);
	return SUCCESS;
}


