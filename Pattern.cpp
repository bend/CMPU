/**
 *
 *       @file  Pattern.cpp
 *
 *      @brief  Pattern parser for id3Rename
 *
 *    @version  1.0
 *       @date  14.06.2011 14:21:40
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */


#include "Pattern.h"

Pattern::Pattern(string pattern){
	this->pattern = pattern;
}

int Pattern::parse(){
	string delim(SEPARATOR);
	if(this->pattern.find_first_of(delim) == string::npos )
		return FAILURE;
	tokenize(this->pattern, delim);
	it = tokens.begin();
	return SUCCESS;
}

int Pattern::next(char* token){
	if(it==tokens.end())
		return EMPTY;
	string s = *it;
	if(strncpy(token,s.c_str(),MAX_TOK) < 0){
		cerr<<"strncpy fail in Pattern::next"<<endl;
		return FAILURE;
	}
	++it;
	return SUCCESS;
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