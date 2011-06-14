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
using namespace std;

#include "Defines.h"

class Id3Rename{

	public:
		Id3Rename(char* song);
		int apply();
	
	private:
		int mv(char* oldName, char* newName);
		int parsePath(char* file, char* path);
		int appendExtension(char* song, char* newName);
		char* song;

};

#endif
