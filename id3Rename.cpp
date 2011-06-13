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

int Id3Rename::parsePath(char* file, char* path){
	if(realpath(file, path) == NULL){
		cerr<<"realPath fail in parsePath";
		return -1;
	}
	string fTemp(path);
	int i = fTemp.find_last_of("/");
	string pathTemp = fTemp.substr(0,i+1);
	if(strncpy(path, pathTemp.c_str(),MAX_PATH) < 0){
		cerr<<"strncpy fail in parsePath";
		return -1;
	}
	return 1;
}

int Id3Rename::appendExtension(char* song, char* newName){
	string tsong(song);
	int period = tsong.find_last_of(".");
	string ext = tsong.substr(period);
	if(strncat(newName, ext.c_str(), MAX_EXT) < 0){
		cerr<<"strncat fail in appendExtensio"<<endl;
		return -1;
	}
	return 0;
}

int Id3Rename::mv(char* oldName, char* newName){
	char resolvedPath[MAX_PATH];
	char completeName[MAX_ALL];
	if(parsePath(oldName, resolvedPath)<0)
		return -1;
	if(strncpy(completeName, resolvedPath,MAX_PATH) <0){
		cerr<<"strncpy fail in mv";
		return -1;
	}
	if(strncat(completeName, newName,MAX_NAME) < 0){
		cerr<<"strncat fail in mv";
		return -1;
	}
	if(rename(oldName, completeName) < 0){
		cerr<<"rename fail in mv";
		return -1;
	}
	return 1;
}

int Id3Rename::apply(){
	ID3_Tag myTag;

	myTag.Link(this->song,ID3TT_ALL);
	ID3_Frame* myFrame = NULL;
	
	char *newName= new char[MAX_ALL];
	myFrame= myTag.Find(ID3FID_LEADARTIST);
	
	if(myFrame!=0){
		char* artist = new char[MAX_ARTIST];
		myFrame->Field(ID3FN_TEXT).Get(artist,MAX_ARTIST);
		strncat(newName,artist,strlen(artist));
		strncat(newName," - ",3);
	}

	myFrame= myTag.Find(ID3FID_TITLE);
	
	if(myFrame!=0){
		char* title = new char[MAX_TITLE];
		myFrame->Field(ID3FN_TEXT).Get(title,MAX_TITLE);
		strncat(newName,title,strlen(title));
	}
	this->appendExtension(this->song, newName);
	this->mv(this->song, newName);
	return 1;
}
