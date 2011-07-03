/**
 *
 *       @file  song.cpp
 *
 *      @brief  Class representing a song
 *
 *    @version  1.0
 *       @date  03.07.2011 16:33:20
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <library/song.h>

Song::Song(string title, int id, string path, map<string, int> artist, string album, string genre, string year, string duration){
	this->title = title;
	this->id = id;
	this->path = path;
	this->artist = artist;
	this->album = album;
	this->genre = genre;
	this->year = year;
	this->duration = duration;
}

Song::Song(string title, int id, string path, string album, string genre, string year, string duration){
	this->title = title;
	this->id = id;
	this->path = path;
	this->album = album;
	this->genre = genre;
	this->year = year;
	this->duration = duration;
}

Song::Song(){}

