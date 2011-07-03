/**
 *
 *       @file  databasequery.h
 *
 *      @brief  queries for the library
 *
 *    @version  1.0
 *       @date  27.06.2011 19:51:47
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

class DatabaseQuery{
	public:
		inline static string addArtist(string name, string details){
			return "INSERT INTO Artist(name, details) VALUES\
				('"+name+"','"+details+"')";
		}

		inline static string addAlbum(string name, string details){
			return "INSERT INTO Album(name, details) VALUES\
				('"+name+"','"+details+"')";
		}

		inline static string addGenre(string name, string details){
			return "INSERT INTO Genre(name, details) VALUES\
				('"+name+"','"+details+"')";
		}

		inline static string addSong(string name, string duration, string path, string details){
			return "INSERT INTO Song(title, duration, path, details) VALUES\
				('"+name+"','"+duration+"','"+path+"','"+details+"')";
		}

		inline static string addAuthor(string id_artist, string id_song, string year){
			return "INSERT INTO Author(id_artist, id_song, year) VALUES\
				('"+id_artist+"','"+id_song+"','"+year+"')";
		}

		inline static string addComposed(string id_artist, string id_album, string year){
			return "INSERT INTO Composed(id_artist, id_album, year) VALUES\
				('"+id_artist +"','"+id_album +"','"+year+"')";
		}
		
		inline static string addIsIn(string id_album, string id_song, string track){
			return "INSERT INTO IsIn(id_album, id_song, track) VALUES\
				('"+id_album+"','"+id_song+"','"+track+"')";
		}
		
		inline static string addGot(string id_genre, string id_song){
			return "INSERT INTO Got(id_genre, id_song) VALUES\
				('"+id_genre+"','"+id_song+"')";
		}

};
