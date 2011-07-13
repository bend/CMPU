/**
 *
 *       @file  song.h
 *
 *      @brief  Class representing a song
 *
 *    @version  1.0
 *       @date  03.07.2011 16:33:20
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef _SONG_H_
#define _SONG_H_
#include <iostream>
#include <map>
using namespace std;

class Song{
	public:
	   	Song(string title, int id, string path, map<string, int> artists, string album="", string genre="", string year="", string	duration="");
	   	Song(string title, int id, string path, string album="", string genre="", string year="", string	duration="");
		Song();
		int setTitle(string title);
		int addArtist(string artist);
		int setAlbum(string album);
		int setGenre(string genre);
		int setYear(string year);
		int setDuration(string duration);
		int setPath(string path);
	private:
		string title;
		int id;
		string path;
		map<string,int> artist;
		string album;
		string genre;
		string year;
		string duration;
};

#endif
