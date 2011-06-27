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
	if(adapter->executeQuery(DatabaseCreate::tableArtist()))
		return FAILURE;
	if(adapter->executeQuery(DatabaseCreate::tableAlbum()))
		return FAILURE;
	if(adapter->executeQuery(DatabaseCreate::tableGenre()))
		return FAILURE;
	if(adapter->executeQuery(DatabaseCreate::tableSong()))
		return FAILURE;
	if(adapter->executeQuery(DatabaseCreate::relationAuthor()))
		return FAILURE;
	if(adapter->executeQuery(DatabaseCreate::relationComposed()))
		return FAILURE;
	if(adapter->executeQuery(DatabaseCreate::relationIsIn()))
		return FAILURE;
	if(adapter->executeQuery(DatabaseCreate::relationGot()))
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

int LibraryManager::addArtist(string name, string details){
	return adapter->executeQuery();
}
