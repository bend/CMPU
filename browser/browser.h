/**
 *
 *       @file  browser.h
 *
 *      @brief  Browse all the files in the directory and subdirs
 *
 *    @version  1.0
 *       @date  14.06.2011 20:11:54
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#ifndef _BROWSER_H_
#define _BROWSER_H_
#include <defines/defines.h>
#include <logger/errorlogger.h>
#include <sys/types.h> 
#include <sys/stat.h>  
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Browser{
	public:
		Browser(string path);
		~Browser();
		int browse();
	private:
		/* methods */
		int sbrowse(string path);
		virtual int apply(string path) = 0;
		void buildPath(string path, string filename, string* res);
		string path;
		

};

#endif
