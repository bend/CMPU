/**
 *
 *       @file  pattern.h
 *
 *      @brief  Pattern parser for id3Rename
 *
 *    @version  1.0
 *       @date  14.06.2011 14:21:40
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#ifndef _PATTERN_H_
#define _PATTERN_H_
#include <iostream>
#include <vector>
using namespace std;

#include "defines.h"

class Pattern{
	public:
		Pattern(string pattern);
		int parse();
		int next(string* token);
		void reset();
	private:
		void tokenize(string str, string delimiters);
		string pattern;
		vector<string> tokens;
		vector<string>::iterator it;

};

#endif
