/**
 *
 *       @file  id3Rename.h
 *
 *      @brief   A music file renamer
 *
 *    @version  1.0
 *       @date   12.06.2011 23:39:21
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include "Id3Rename.h"

Id3Rename::Id3Rename(char* song){
	this->song = song;
}

int Id3Rename::parsePath(char* file, char* path){
	if(realpath(file, path) == NULL){
		cerr<<"realPath fail in Id3Rename::parsePath"<<endl;
		return FAILURE;
	}
	string fTemp(path);
	int i = fTemp.find_last_of("/");
	string pathTemp = fTemp.substr(0,i+1);
	if(strncpy(path, pathTemp.c_str(),MAX_PATH) < 0){
		cerr<<"strncpy fail in Id3Rename::parsePath"<<endl;
		return FAILURE;
	}
	return SUCCESS;
}

int Id3Rename::appendExtension(char* song, char* newName){
	string tsong(song);
	int period = tsong.find_last_of(".");
	string ext = tsong.substr(period);
	if(strncat(newName, ext.c_str(), MAX_EXT) < 0){
		cerr<<"strncat fail in Id3Rename::appendExtension"<<endl;
		return FAILURE;
	}
	return SUCCESS;
}

int Id3Rename::mv(char* oldName, char* newName){
	char resolvedPath[MAX_PATH];
	char completeName[MAX_ALL];
	if(this->parsePath(oldName, resolvedPath)<0)
		return FAILURE;
	if(strncpy(completeName, resolvedPath,MAX_PATH) <0){
		cerr<<"strncpy fail in Id3Rename::mv"<<endl;
		return FAILURE;
	}
	if(strncat(completeName, newName,MAX_NAME) < 0){
		cerr<<"strncat fail in Id3Rename::mv"<<endl;
		return FAILURE;
	}
	if(rename(oldName, completeName) < 0){
		cerr<<"rename fail in Id3Rename::mv"<<endl;
		return FAILURE;
	}
	return SUCCESS;
}

int Id3Rename::apply(){
	ID3_Tag myTag;
	ID3_Frame* myFrame = NULL;
	char *newName= new char[MAX_ALL];
	char* title = new char[MAX_TITLE];
	char* artist = new char[MAX_ARTIST];
	
	myTag.Link(this->song,ID3TT_ALL);
	myFrame= myTag.Find(ID3FID_LEADARTIST);
	if(myFrame!=0){
		myFrame->Field(ID3FN_TEXT).Get(artist,MAX_ARTIST);
		if(strncat(newName,artist,MAX_ARTIST) < 0){
			cerr<<"strncat fail in Id3Rename::apply"<<endl;
			return FAILURE;
		}
	} 

	myFrame= myTag.Find(ID3FID_TITLE);
	
	if(myFrame!=0){
		myFrame->Field(ID3FN_TEXT).Get(title,MAX_TITLE);
		if(strlen(newName) == 0){
			if(strncat(newName," - ",3) < 0){
				cerr<<"strncat fail in Id3Rename::apply"<<endl;
				return FAILURE;
			}
		}
		strncat(newName,title,strlen(title));
	}else{
		cerr<<"Could not rename file: title not found"<<endl;
		return FAILURE;
	}
	if(this->appendExtension(this->song, newName) < 0)
		return FAILURE;
	if(this->mv(this->song, newName) < 0)
		return FAILURE;
	return SUCCESS;
}
