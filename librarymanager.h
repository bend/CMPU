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
#ifndef _LIBRARY_MANGER_H_
#define _LIBRARY_MANGER_H_
#include "sqliteadapter.h"
#include "defines.h"

class LibraryManager{
	public:
		LibraryManager(string libName);
		int createLibrary();
		int openLibrary();
		void closeLibrary();

		int addArtist(string name);
		int addAlbum(string name,string genre, int year=0);
		int addGenre(string name);
		int addSong(string name, string artist="");



};

#endif
