/**
 *
 *       @file  id3tagger.h
 *
 *      @brief  Tag a song file
 *
 *    @version  1.0
 *       @date  21.06.2011 17:37:34
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#ifndef _ID3TAGGER_H_
#define _ID3TAGGER_H_
#include <defines/defines.h>
#include <logger/errorlogger.h>
#include <id3tool/pattern.h>
#include <id3/tag.h>
#include <iostream>
using namespace std;
class Id3Tagger{

	public:
		Id3Tagger(string song, Pattern* pattern);
		int apply();
		int tagAlbum(string name);
		int tagArtist(string name);
		int tagTitle(string name);
		int tagYear(string year);
	private:
		string filename;
		Pattern* pattern;
		ID3_Tag myTag;

};

#endif
