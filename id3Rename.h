/**
 *
 *       @file  id3Rename.h
 *
 *      @brief   A music file renamer
 *
 *    @version  1.0
 *       @date   12.06.2011 23:39:21
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef _ID3RENAME_H_
#define _ID3RENAME_H_

#include <id3/tag.h>
#include <iostream>
#include <fstream>
using namespace std;

#include "defines.h"
#include "pattern.h"

class Id3Rename{

	public:
		/* methods */
		Id3Rename(char* song, Pattern* pattern);
		~Id3Rename();
		int apply();
	
	private:
		/* methods */
		int renameIfExist(char* path);
		int mv(char* oldName, char* newName);
		int parsePath(char* file, char* path);
		int appendDelimiter(char* newName);
		int appendExtension(char* newName);
		int appendArtist(char* newName);
		int appendTitle(char* newName);
		int appendAlbum(char* newName);
		int appendYear(char* newName);

		/* arguments */
		char* song;
		Pattern* pattern;
		ID3_Tag myTag;

};

#endif
