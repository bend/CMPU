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

#include <id3renamer/id3Renamer.h>

Id3Rename::Id3Rename(char* song, Pattern* pattern){
	this->song = song;
	this->pattern = pattern;
}

Id3Rename::~Id3Rename(){}


int Id3Rename::apply(){
	this->myTag.Link(this->song,ID3TT_ALL);
	this->pattern->reset();
	char *newName= new char[MAX_ALL];
	bool first = true;
	string *token = new string();
	while(pattern->next(token) != EMPTY){
		if(!first)
			appendDelimiter(newName);
		else 
			first = false;
		if(*token == ARTIST){	
			if(appendArtist(newName) == FAILURE)
				first = true;
		}else if(*token == TITLE){
			if(appendTitle(newName) == FAILURE)
				first = true;
		}else if(*token == ALBUM){
			if(appendAlbum(newName) == FAILURE)
				first = true;
		}else if(*token == YEAR){
			if(appendYear(newName) == FAILURE)
				first = true;
		}else{
			cerr<<"Error: Pattern not found: "<<*token<<endl;
			delete[] newName;
			delete token;
			return FAILURE;
		}
	}
	if(strlen(newName) == 0 || newName[0]==' '){
		delete[] newName;
		delete token;
		return SUCCESS;
	}
	if(this->appendExtension(newName) < 0){
		delete[] newName;
		delete token;
		return FAILURE;
	}
	if(this->mv(this->song, newName) < 0){
		delete[] newName;
		delete token;
		return FAILURE;
	}
	return SUCCESS;
}

int Id3Rename::parsePath(char* file, char* path){
	if(realpath(file, path) == NULL){
		cerr<<"realPath fail in Id3Rename::parsePath"<<endl;
		return FAILURE;
	}
	string fTemp(path);
	int i = fTemp.find_last_of("/");
	string pathTemp = fTemp.substr(0,i+1);
	if(strncpy(path, pathTemp.c_str(), MAX_PATH) < 0){
		cerr<<"strncpy fail in Id3Rename::parsePath"<<endl;
		return FAILURE;
	}
	return SUCCESS;
}
int Id3Rename::appendDelimiter(char* newName){
	if(strncat(newName, " - ", 3) < 0)
		return FAILURE;
	return SUCCESS;
}

int Id3Rename::appendExtension(char* newName){
	string tsong(this->song);
	int period = tsong.find_last_of(".");
	string ext = tsong.substr(period);
	if(strncat(newName, ext.c_str(), MAX_EXT) < 0){
		cerr<<"strncat fail in Id3Rename::appendExtension"<<endl;
		return FAILURE;
	}
	return SUCCESS;
}

int Id3Rename::renameIfExist(char* path){
	fstream myFile;
	myFile.open (path,ios_base::in);
	/* file already exist, rename it */
	if(myFile){
		int i = 1;
		string tsong = path;
		string newName;
		int period = tsong.find_last_of(".");
		string name = tsong.substr(0,period);
		string ext = tsong.substr(period);
		while(myFile){
			stringstream oss;
			oss <<  name << '(' << i << ')'<<ext;
			newName = oss.str();
			myFile.close();
			myFile.open(newName.c_str());
			i++;
		}
		if(strncpy(path,newName.c_str(),MAX_PATH) < 0){
			cerr<<"strncpy fail in Id3Rename::renameIfExist"<<endl;
			return FAILURE;
		}
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
	if(renameIfExist(completeName) == FAILURE)
		return FAILURE;
	if(rename(oldName, completeName) < 0){
		cerr<<"rename fail in Id3Rename::mv"<<endl;
		return FAILURE;
	}
	return SUCCESS;
}


int Id3Rename::appendArtist(char* newName){
	ID3_Frame* myFrame = NULL;
	char* artist = new char[MAX_ARTIST];
	myFrame= myTag.Find(ID3FID_LEADARTIST);
	if(myFrame!=0){
		myFrame->Field(ID3FN_TEXT).Get(artist,MAX_ARTIST);
		if(strncat(newName,artist,MAX_ARTIST) < 0){
			cerr<<"strncat fail in Id3Rename::appendArtist"<<endl;
			return FAILURE;
		}
	}else return FAILURE;
	return SUCCESS;	
}
int Id3Rename::appendTitle(char* newName){
	ID3_Frame* myFrame = NULL;
	char* title = new char[MAX_TITLE];
	myFrame= myTag.Find(ID3FID_TITLE);
	if(myFrame!=0){
		myFrame->Field(ID3FN_TEXT).Get(title,MAX_TITLE);
		if(strncat(newName,title,MAX_TITLE) < 0){
			cerr<<"strncat fail in Id3Rename::appendTitle"<<endl;
			return FAILURE;
		}
	}else return FAILURE;
	return SUCCESS;
}
int Id3Rename::appendAlbum(char* newName){
	ID3_Frame* myFrame = NULL;
	char* title = new char[MAX_ALBUM];
	myFrame= myTag.Find(ID3FID_ALBUM);
	if(myFrame!=0){
		myFrame->Field(ID3FN_TEXT).Get(title,MAX_ALBUM);
		if(strncat(newName,title,MAX_ALBUM) < 0){
			cerr<<"strncat fail in Id3Rename::appendTitle"<<endl;
			return FAILURE;
		}
	}else return FAILURE;
	return SUCCESS;
}
int Id3Rename::appendYear(char* newName){
	ID3_Frame* myFrame = NULL;
	char* title = new char[MAX_YEAR];
	myFrame= myTag.Find(ID3FID_YEAR);
	if(myFrame!=0){
		myFrame->Field(ID3FN_TEXT).Get(title,MAX_YEAR);
		if(strncat(newName,title,MAX_YEAR) < 0){
			cerr<<"strncat fail in Id3Rename::appendTitle"<<endl;
			return FAILURE;
		}
	}else return FAILURE;
	return SUCCESS;
}
