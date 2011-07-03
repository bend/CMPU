/**
 *
 *       @file  testlibrary.cpp
 *
 *      @brief  Testing file for class Library
 *
 *    @version  1.0
 *       @date  03.07.2011 09:14:29
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#include <tests/testlibrary.h>
void testLibrary(){
	LibraryManager l(DB);
	assert(l.createLibrary()==SUCCESS);		/* Create the Lib */
	assert(l.createLibrary()==FAILURE);		/* Lib already exists */
	
	/* Add the artists */
	assert(l.addArtist("TestArt","TestDet")==SUCCESS);
	int id1 = l.getLastInsertedId();
	assert(l.addArtist("TestArt1","TestDet1")==SUCCESS);
	int id2 = l.getLastInsertedId();
	assert(l.addArtist("TestArt2","TestDet2")==SUCCESS);
	int id3 = l.getLastInsertedId();

	/* Add the Albums */
	assert(l.addAlbum("TestAlb","TestDet") == SUCCESS);
	int id4 = l.getLastInsertedId();
	assert(l.addAlbum("TestAlb1","TestDet1") == SUCCESS);
	int id5 = l.getLastInsertedId();

	/* Add the Genres */
	assert(l.addGenre("ROCK","It Rocks") == SUCCESS);
	int id6 = l.getLastInsertedId();
	assert(l.addGenre("POP", "It Pops") == SUCCESS);
	int id7 = l.getLastInsertedId();

	/* Add songs */
	assert(l.addSong("Song1", "det1","/thesong.mp3","2010") == SUCCESS);
	int id8 = l.getLastInsertedId();
	assert(l.addSong("Song2", "det2","/thesong2.mp3","2010") == SUCCESS);
	int id9 = l.getLastInsertedId();

	/* Add Authors */
	assert(l.addAuthor(toString(id1),toString(id8),"2010") == SUCCESS);
	assert(l.addAuthor(toString(id1),toString(id8),"2010") == SUCCESS); /* Not an error */
	assert(l.addAuthor(toString(id2), toString(id4),"2010") == SUCCESS);
	
	/* Add Composed */
	assert(l.addComposed(toString(id3),toString(id9),"2008") == SUCCESS);
	assert(l.addComposed(toString(id2),toString(id9),"2007") == SUCCESS);

	/* Add IsIn */
	assert(l.addIsIn(toString(id3),toString(id5),"01") == SUCCESS);
	assert(l.addIsIn(toString(id2),toString(id4),"01") == SUCCESS);

	/* AddGot */
	assert(l.addGot(toString(id6), toString(id8)) == SUCCESS);
	assert(l.addGot(toString(id7), toString(id9)) == SUCCESS);
}

