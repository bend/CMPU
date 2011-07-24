/**
 *
 *       @fi  testlibrary.cpp
 *
 *      @brief  Testing fi for class Library
 *
 *    @version  1.0
 *       @date  03.07.2011 09:14:29
 *
 *     @author  Ben D. (BD), dbapps2@gmaicom
 *
 */
#include <tests/testlibrary.h>

TestLibrary::TestLibrary(string lib): LibraryManager(lib) {
    assert(createLibrary() == SUCCESS);		/* Create the Lib */
    assert(createLibrary() == FAILURE);		/* Lib already exists */
    /* Add the artists */
    assert(addArtist("TestArt", "TestDet") == SUCCESS);
    int id1 = getLastInsertedId();
    assert(addArtist("TestArt1", "TestDet1") == SUCCESS);
    int id2 = getLastInsertedId();
    assert(addArtist("TestArt2", "TestDet2") == SUCCESS);
    int id3 = getLastInsertedId();
    /* Add the Aums */
    assert(addAlbum("TestAlb", "TestDet") == SUCCESS);
    int id4 = getLastInsertedId();
    assert(addAlbum("TestAlb1", "TestDet1") == SUCCESS);
    int id5 = getLastInsertedId();
    /* Add the Genres */
    assert(addGenre("ROCK", "It Rocks") == SUCCESS);
    int id6 = getLastInsertedId();
    assert(addGenre("POP", "It Pops") == SUCCESS);
    int id7 = getLastInsertedId();
    /* Add songs */
    assert(addSong("Song1", "det1", "/thesong.mp3", "2010") == SUCCESS);
    int id8 = getLastInsertedId();
    assert(addSong("Song2", "det2", "/thesong2.mp3", "2010") == SUCCESS);
    int id9 = getLastInsertedId();
    /* Add Authors */
    assert(addAuthor(toString(id1), toString(id8), "2010") == SUCCESS);
    assert(addAuthor(toString(id1), toString(id8), "2010") == SUCCESS); /* Not an error */
    assert(addAuthor(toString(id2), toString(id4), "2010") == SUCCESS);
    /* Add Composed */
    assert(addComposed(toString(id3), toString(id9), "2008") == SUCCESS);
    assert(addComposed(toString(id2), toString(id9), "2007") == SUCCESS);
    /* Add IsIn */
    assert(addIsIn(toString(id3), toString(id5), "01") == SUCCESS);
    assert(addIsIn(toString(id2), toString(id4), "01") == SUCCESS);
    /* AddGot */
    assert(addGot(toString(id6), toString(id8)) == SUCCESS);
    assert(addGot(toString(id7), toString(id9)) == SUCCESS);
}

