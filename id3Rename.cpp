/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description: A music file renamer.
 *
 *        Version:  1.0
 *        Created:  11.06.2011 19:58:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ben D. (BD), dbapps2@gmail.com
 *        Company:  dbapps
 *
 * =====================================================================================
 */

#include "Id3Rename.h"

Id3Rename::Id3Rename(char* song){
	this->song = song;
}

int Id3Rename::mv(char* oldName, char* newName){
	int result= rename(oldName , newName );
	if (result<0)
		perror( "Error renaming file" );
	return result;
}

int Id3Rename::apply(){
	ID3_Tag myTag;

	myTag.Link(this->song,ID3TT_ALL);
	ID3_Frame* myFrame = NULL;
	
	char *newName= new char[2048];
	myFrame= myTag.Find(ID3FID_LEADARTIST);
	
	if(myFrame!=0){
		char* artist = new char[1024];
		myFrame->Field(ID3FN_TEXT).Get(artist,1024);
		strncat(newName,artist,strlen(artist));
		strncat(newName," - ",3);
	}

	myFrame= myTag.Find(ID3FID_TITLE);
	
	if(myFrame!=0){
		char* title = new char[1024];
		myFrame->Field(ID3FN_TEXT).Get(title,1024);
		strncat(newName,title,strlen(title));
	}

	string pathName = this->song;
	int period = pathName.find_last_of(".");
	string ext = pathName.substr(period);
	strcat(newName,ext.c_str());
	this->mv(this->song, newName);
	return 1;
}
