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

#include <library/librarymanager.h>

LibraryManager::LibraryManager(string libname){
	this->libname=libname;
	this->adapter = new SqliteAdapter();
}

int LibraryManager::createLibrary(){
	if(	adapter->openDatabase(libname) == FAILURE)
		return FAILURE;
	if(adapter->executeQuery(DatabaseDefs::tableArtist()))
		return FAILURE;
	if(adapter->executeQuery(DatabaseDefs::tableAlbum()))
		return FAILURE;
	if(adapter->executeQuery(DatabaseDefs::tableGenre()))
		return FAILURE;
	if(adapter->executeQuery(DatabaseDefs::tableSong()))
		return FAILURE;
	if(adapter->executeQuery(DatabaseDefs::tableAuthor()))
		return FAILURE;
	if(adapter->executeQuery(DatabaseDefs::relationComposed()))
		return FAILURE;
	if(adapter->executeQuery(DatabaseDefs::relationIsIn()))
		return FAILURE;
	if(adapter->executeQuery(DatabaseDefs::relationGot()))
		return FAILURE;
	return SUCCESS;
}


int LibraryManager::openLibrary(){
	if(	adapter->openDatabase(libname) == FAILURE)
		return FAILURE;
	return SUCCESS;
}

void LibraryManager::closeLibrary(){
	adapter->closeDatabase();
}
