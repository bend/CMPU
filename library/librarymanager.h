/**
 *
 *       @file  librarymanager.h
 *
 *      @brief Wrapper around music library
 *
 *    @version  1.0
 *       @date  18.06.2011 19:02:58
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#ifndef _LIBRARY_MANAGER_H_
#define _LIBRARY_MANAGER_H_
#include <sqladapter/sqliteadapter.h>
#include <defines/defines.h>
#include <defines/databasecreate.h>
#include <defines/databasequery.h>

class LibraryManager{
	public:
		LibraryManager(string libName);
		int createLibrary();
		int openLibrary();
		void closeLibrary();

		int addArtist(string name, string details="");
		int addAlbum(string name, string details="");
		int addGenre(string name, string details="");
		int addSong(string title, int duration, string artist="");

	private:
		string libname;
		SqliteAdapter *adapter;



};

#endif
