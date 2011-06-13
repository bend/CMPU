/*
 * =====================================================================================
 *
 *       Filename:  id3Rename.h
 *
 *    Description:  A music file renamer
 *
 *        Version:  1.0
 *        Created:  12.06.2011 23:39:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ben D. (BD), dbapps2@gmail.com
 *        Company:  dbapps
 *
 * =====================================================================================
 */
#include <id3/tag.h>
#include <iostream>

#include "Defines.h"
using namespace std;

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
