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
	return adapter->executeQuery(DatabaseQuery::addArtist(name, details));
}

int LibraryManager::addAlbum(string name, string details){
	return adapter->executeQuery(DatabaseQuery::addAlbum(name, details));
}

int LibraryManager::addGenre(string name, string details){
	return adapter->executeQuery(DatabaseQuery::addGenre(name, details));
}

int LibraryManager::addSong(string name, string duration, string details){
	return adapter->executeQuery(DatabaseQuery::addSong(name, duration ,details));
}

int LibraryManager::addAuthor(string id_artist, string id_song, string year){
	return adapter->executeQuery(DatabaseQuery::addAuthor(id_artist, id_song, year));
}

int LibraryManager::addComposed(string id_artist, string id_album, string year){
	return adapter->executeQuery(DatabaseQuery::addComposed(id_artist, id_album, year));
}

int LibraryManager::addIsIn(string id_album, string id_song, string track){
	return adapter->executeQuery(DatabaseQuery::addIsIn(id_album, id_song, track));
}

int LibraryManager::addGot(string id_genre, string id_song){
	return adapter->executeQuery(DatabaseQuery::addGot(id_genre, id_song));
}

int LibraryManager::getLastInsertedId(){
	return adapter->getLastInsertedId();
}
