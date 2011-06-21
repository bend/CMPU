/**
 *
 *       @file  id3tagger.cpp
 *
 *      @brief  Tag a song file
 *
 *    @version  1.0
 *       @date  21.06.2011 17:37:44
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <id3tool/id3tagger.h>

Id3Tagger::Id3Tagger(string filename){
	this->filename = filename;
}

int Id3Tagger::tagAlbum(string name){
	return SUCCESS;
}

int Id3Tagger::tagArtist(string name){
	return SUCCESS; 
}

int Id3Tagger::tagSong(string name){
	return SUCCESS; 
}

int Id3Tagger::tagYear(string year){
	return SUCCESS; 
}
