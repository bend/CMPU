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
#include <defines/defines.h>
#include <id3/tag.h>
#include <iostream>
using namespace std;
class Id3Tagger{

	public:
		Id3Tagger(string filename);
		int tagAlbum(string name);
		int tagArtist(string name);
		int tagTitle(string name);
		int tagYear(string year);
		int tagGenre(string genre);
	private:
		string filename;
		ID3_Tag myTag;

};
