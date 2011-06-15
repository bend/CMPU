/**
 *
 *       @file  pattern.cpp
 *
 *      @brief  Pattern parser for id3Rename
 *
 *    @version  1.0
 *       @date  14.06.2011 14:21:40
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */


#include "pattern.h"

Pattern::Pattern(string pattern){
	this->pattern = pattern;
}

Pattern::~Pattern(){}

int Pattern::parse(){
	string delim(SEPARATOR);
	if(this->pattern.length() == 0){
		cerr<<"Error:Invalid pattern"<<endl;
		return FAILURE;
	}
	tokenize(this->pattern, delim);
	it = tokens.begin();
	return SUCCESS;
}

int Pattern::next(string *token){
	if(it==tokens.end())
		return EMPTY;
	*token = *it;
	++it;
	return SUCCESS;
}

void Pattern::reset(){
	it = tokens.begin();
}

void Pattern::tokenize(string str, string delimiters ){
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    string::size_type pos     = str.find_first_of(delimiters, lastPos);
    while (string::npos != pos || string::npos != lastPos)
    {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }
}
