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
#include "defines.h"

#include <iostream>
using namespace std;

class Browser{
	public:
		Browser(string path);
	protected:
		/* methods */
		int browse();
		virtual int apply();
	private:
		/* methods */
		int sbrowse(char* path);
		int buildPath();
		string path;

};

#endif
