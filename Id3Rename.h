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
 *       Compiler:  g++
 *
 *         Author:  Ben D. (BD), dbapps2@gmail.com
 *
 * =====================================================================================
 */
#include <id3/tag.h>
#include <iostream>

#include "Defines.h"
using namespace std;

class Id3Rename{

	public:

		/** 
		 * @brief Constructor for class Id3Rename
		 * @param song the path to the song file
		 *
		 */
		Id3Rename(char* song);

		/**
		 * @brief Applies the rename to the file given in constructor
		 *
		 */
		int apply();
	
	private:
		int mv(char* oldName, char* newName);
		int parsePath(char* file, char* path);
		int appendExtension(char* song, char* newName);
		char* song;

};
