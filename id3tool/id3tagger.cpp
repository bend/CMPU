/**
 *
 *       @file  id3tagger.cpp
 *
 *      @brief  Tag a song file
 *
 *    @version  1.0
 *       @date  21.06.2011 17:37:44
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <id3tool/id3tagger.h>

Id3Tagger::Id3Tagger(string filename, Pattern* pattern){
	this->filename = filename;
	this->pattern = pattern;
}

int Id3Tagger::apply(){
	this->myTag.Link(this->filename.c_str(),ID3TT_ALL);
	this->pattern->reset();
	string *token = new string();
	while(pattern->next(token) != EMPTY){
		if(*token == ARTIST){
			if(pattern->next(token)==SUCCESS){
				if(tagArtist(*token) == FAILURE)
					return FAILURE;
			}else return FAILURE;
		}else if(*token == TITLE){
			if(pattern->next(token)==SUCCESS){
				if(tagTitle(*token) == FAILURE)
					return FAILURE;
			}else return FAILURE;
		}else if(*token == ALBUM){
			if(pattern->next(token)==SUCCESS){
				if(tagAlbum(*token) == FAILURE)
					return FAILURE;
			}else return FAILURE;
		}else if(*token == YEAR){
			if(pattern->next(token)==SUCCESS){
				if(tagYear(*token) == FAILURE)
					return FAILURE;
			}else return FAILURE;
		}else{
			cerr<<"Pattern not found"<<*token<<endl;
			delete token;
			return FAILURE;
		}
	}
	delete token;
	return SUCCESS;
}

int Id3Tagger::tagAlbum(string name){
	ID3_Frame* myFrame = NULL;
	ID3_Field* myField = NULL;
	myFrame= myTag.Find(ID3FID_ALBUM);
	if(myFrame != 0){
		myField= myFrame->GetField(ID3FN_TEXT);
		myField->Set(name.c_str());
		this->myTag.Update();
		return SUCCESS;
	}
	return FAILURE;
}

int Id3Tagger::tagArtist(string name){
	ID3_Frame* myFrame = NULL;
	ID3_Field* myField = NULL;
	myFrame= myTag.Find(ID3FID_LEADARTIST);
	if(myFrame != 0){
		myField= myFrame->GetField(ID3FN_TEXT);
		myField->Set(name.c_str());
		this->myTag.Update();
		return SUCCESS;
	}
	return FAILURE;
}

int Id3Tagger::tagTitle(string name){
	ID3_Frame* myFrame = NULL;
	ID3_Field* myField = NULL;
	myFrame= myTag.Find(ID3FID_TITLE);
	if(myFrame != 0){
		myField= myFrame->GetField(ID3FN_TEXT);
		myField->Set(name.c_str());
		this->myTag.Update();
		return SUCCESS;
	}
	return FAILURE;
}

int Id3Tagger::tagYear(string year){
	ID3_Frame* myFrame = NULL;
	ID3_Field* myField = NULL;
	myFrame= myTag.Find(ID3FID_YEAR);
	if(myFrame != 0){
		myField= myFrame->GetField(ID3FN_TEXT);
		myField->Set(year.c_str());
		this->myTag.Update();
		return SUCCESS;
	}
	return FAILURE;
}

