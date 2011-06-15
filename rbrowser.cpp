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

#include "rbrowser.h"

RBrowser::RBrowser(string path, Pattern* pattern):Browser(path){
	this->pattern = pattern;
}


int RBrowser::apply(string str){
	Id3Rename r(const_cast<char*>(str.c_str()), this->pattern);
	return r.apply();
}
