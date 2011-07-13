/**
 *
 *       @file  tbrowser.h
 *
 *      @brief  
 *
 *    @version  1.0
 *       @date  15.06.2011 16:02:58
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#ifndef _TBROWSER_H_
#define _TBROWSER_H_
#include <browser/browser.h>
#include <id3tool/id3tagger.h>
#include <utils/pattern.h>

#include <iostream>
#include <set>
using namespace std;
class TBrowser: public Browser{
	public:
		TBrowser(string test, Pattern *pattern, set<string> *vect );
		~TBrowser();
	private:
		virtual int apply(string str);
		set<string> *ext;
		Pattern *pattern;

};

#endif
