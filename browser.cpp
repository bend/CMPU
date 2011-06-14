/**
 *
 *       @file  browser.cpp
 *
 *      @brief  Browse all the files in the directory and subdirs
 *
 *    @version  1.0
 *       @date  14.06.2011 20:11:02
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include "browser.h"

Browser::Browser(string path){
	this->path = path;
}

int Browser::browse(){
	return SUCCESS;
}

int Browser::sbrowse(char* path){
	path = NULL;
	return SUCCESS;
}

int Browser::buildPath(){
	return SUCCESS;
}

int Browser::apply(){
	return SUCCESS;
}
