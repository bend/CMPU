/**
 *
 *       @file  test.cpp
 *
 *      @brief  
 *
 *    @version  1.0
 *       @date  15.06.2011 16:02:57
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <browser/rbrowser.h>

RBrowser::RBrowser(string path, Pattern* pattern, set<string> *ext):Browser(path){
	this->pattern = pattern;
	this->ext = ext;
}

RBrowser::~RBrowser(){}

int RBrowser::apply(string str){
	int period = str.find_last_of(".");
	string e = str.substr(period+1);
	if(ext->find(e)!= ext->end()){
		Id3Rename r(str, this->pattern);
		return r.apply();
	}
	return SUCCESS;
}



