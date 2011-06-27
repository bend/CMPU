/**
 *
 *       @file  database.h
 *
 *      @brief  Database defines
 *
 *    @version  1.0
 *       @date  23.06.2011 23:06:10
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 */
#ifndef _DATABASE_DEFS_H_
#define _DATABASE_DEFS_H_

class DatabaseCreate{
	public:
		inline static string tableArtist(){
			return "CREATE TABLE Artist(\
				id		INTEGER PRIMARY KEY,\
				name	TEXT NOT NULL,\
				details TEXT);";
		}

		inline static string tableAlbum(){
			return "CREATE TABLE Album(\
				id		INTEGER PRIMARY KEY,\
				name	TEXT NOT NULL,\
				details TEXT);";
		}

		inline static string tableGenre(){
			return "CREATE TABLE Genre(\
				id		INTEGER PRIMARY KEY,\
				name	TEXT NOT NULL,\
				details TEXT);";
		}

		inline static string tableSong(){
			return "CREATE TABLE Song(\
				id		 INTEGER PRIMARY KEY,\
				title	 TEXT NOT NULL,\
				duration INTEGER NOT NULL,\
				details  TEXT);";
		}


		inline static string relationAuthor(){
			return "CREATE TABLE Author(\
				id_artist INTEGER PRIMARY KEY,\
				id_song INTEGER,\
				year INTEGER,\
				FOREIGN KEY(id_artist) REFERENCES Artist(id),\
				FOREIGN KEY(id_song)   REFERENCES Song(id));";
		}

		inline static string relationComposed(){
			return "CREATE TABLE Composed(\
				id_artist INTEGER,\
				id_album INTEGER,\
				year INTEGER,\
				FOREIGN KEY(id_artist) REFERENCES Artist(id),\
				FOREIGN KEY(id_album)  REFERENCES Album(id));";
		}

		inline static string relationIsIn(){
			return "CREATE TABLE IsIn(\
				id_album INTEGER,\
				id_song INTEGER,\
				track INTEGER,\
				FOREIGN KEY(id_album) REFERENCES Album(id),\
				FOREIGN KEY(id_song)  REFERENCES Song(id));";
		}

		inline static string relationGot(){
			return "CREATE TABLE Got(\
				id_genre INTEGER,\
				id_song INTEGER,\
				FOREIGN KEY(id_genre) REFERENCES Genre(id),\
				FOREIGN KEY(id_song)  REFERENCES Song(id));";
		}

		inline static string createDatabase(){
			return "CREATE DATABASE MUSIC_LIBRARY;";
		}

		inline static string useDatabase(){
			return "USE MUSIC_LIBRARY";
		}


};

#endif
