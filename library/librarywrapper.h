/**
 *
 *       @file  librarywrapper.cpp
 *
 *      @brief  A wrapper to the library hidding insertion difficulties
 *      		It automatically creates an author, genre, ... 
 *      		if not already existing in the library
 *
 *    @version  1.0
 *       @date  03.07.2011 14:41:44
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#ifndef _LIBRARY_WRAPPER_H_
#define _LIBRARY_WRAPPER_H_
#include <library/librarymanager.h>
#include <library/song.h>
#include <iostream>
#include <map>
#include <list>
using namespace std;

class LibraryWrapper:public LibraryManager{
	public:
		/**
		 * @brief Constructor 
		 * @param lib the music library name, if the lib does not exist, the lib will be created
		 */
		LibraryWrapper(string lib);

		/**
		 * @brief Loads the song info referenced by the path
		 * @param path the path to the song
		 * @param song a pointer to the song object
		 * @return SUCCESS if succeeded, FAILURE otherwise (or if song not in lib)
		 */
		int loadSong(string path, Song* song);
		
		/**
		 * @brief Loads the song info referenced by the id
		 * @param path the path to the song
		 * @param song a pointer to the song object
		 * @return SUCCESS if succeeded, FAILURE otherwise (or if song not in lib)
		 */
		int loadSong(int id, Song* song);
		
		/**
		 * @brief returns a map containing song names and there id of a specific genre
		 * @param genre the genre name
		 * @param m a pointer to a empty map
		 * @return SUCCESS if succeded, FAILURE otherwise (or if nothing found)
		 */
		int loadSongOfGenre(string genre, map<string,int> *m);
		
		/**
		 * @brief returns a map containing song names and there id of a specific genre
		 * @param genre the genre id
		 * @param m a pointer to a empty map
		 * @return SUCCESS if succeded, FAILURE otherwise (or if nothing found)
		 */
		int loadSongOfGenre(int genre, map<string,int> *m);
		
		/**
		 * @brief returns a map containing song names and there id of a specific Artist
		 * @param artist the artist name
		 * @param m a pointer to a empty map
		 * @return SUCCESS if succeded, FAILURE otherwise (or if nothing found)
		 */
		int loadSongOfArtist(string artist, map<string,int> *m);
		
		/**
		 * @brief returns a map containing song names and there id of a specific Artist
		 * @param artist the artist id
		 * @param m a pointer to a empty map
		 * @return SUCCESS if succeded, FAILURE otherwise (or if nothing found)
		 */
		int loadSongOfArtist(int artist, map<string,int> *m);
		
		/**
		 * @brief returns a map containing song names and there id of a specific Album
		 * @param album the album name
		 * @param m a pointer to a empty map
		 * @return SUCCESS if succeded, FAILURE otherwise (or if nothing found)
		 */
		int loadSongOfAlbum(string album,map<string,int> *m);
		
		/**
		 * @brief returns a map containing song names and there id of a specific Album
		 * @param artist the artist id
		 * @param m a pointer to a empty map
		 * @return SUCCESS if succeded, FAILURE otherwise (or if nothing found)
		 */
		int loadSongOfAlbum(int album,map<string,int> *m);
		
		/**
		 * @brief returns a map containing song names and there id of a specific Year
		 * @param year the year
		 * @param m a pointer to a empty map
		 * @return SUCCESS if succeded, FAILURE otherwise (or if nothing found)
		 */
		int loadSongOfYear(string year, map<string,int> *m);

		/**
		 * @brief returns a map containing song names and there id matching the search
		 * @param s the search query
		 * @param m a pointer to a empty map
		 * @return SUCCESS if succeded, FAILURE otherwise (or if nothing found)
		 */
		int searchSong(string s, map<string,int> *m);
		
		/**
		 * @brief returns a map containing artist names and there id matching the search
		 * @param s the search query
		 * @param m a pointer to a empty map
		 * @return SUCCESS if succeded, FAILURE otherwise (or if nothing found)
		 */
		int searchArtist(string s, map<string,int> *m);

		/**
		 * @brief returns a map containing genre names and there id matching the search
		 * @param s the search query
		 * @param m a pointer to a empty map
		 * @return SUCCESS if succeded, FAILURE otherwise (or if nothing found)
		 */
		int searchGenre(string s, map<string,int> *m);
			
		/**
		 * @brief adds a song to the library if not existing
		 * if the Artist/Genre/Album does not exit, they will be created 
		 * @param title the song title
		 * @param path the path to the song
		 * @param artists a list of artists
		 * @param duration the song duration
		 * @param year the song year
		 * @param genre the song genre
		 * @return SUCCESS or FAILURE
		 */	
		int addSong(string title, string path, list<string> artists, string duration, string year, string album, string genre);
		
		/**
		 * @brief adds a song to the library if not existing
		 * if the Artist/Genre/Album does not exit, they will be created 
		 * @param song the Song object
		 * @return SUCCESS or FAILURE
		 */	
		int addSong(Song *s);
		int updateSong(Song *s);
};

#endif
