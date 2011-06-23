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
#include <iostream>
#include <sstream>
using namespace std;

#include <defines/defines.h>
#include <id3tool/pattern.h>
#include <logger/errorlogger.h>

class Id3Rename{

	public:
		/* methods */
		Id3Rename(string song, Pattern* pattern);
		~Id3Rename();
		int apply();
	
	private:
		/* methods */
		int renameIfExist(char* path);
		int mv(const char* oldName, char* newName);
		int parsePath(const char* file, char* path);
		int appendDelimiter(char* newName);
		int appendExtension(char* newName);
		int appendArtist(char* newName);
		int appendTitle(char* newName);
		int appendAlbum(char* newName);
		int appendYear(char* newName);

		/* arguments */
		string song;
		Pattern* pattern;
		ID3_Tag myTag;

};

#endif
