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

#include <defines/defines.h>
#include <logger/errorlogger.h>

class Pattern {
public:
    /**
     * @brief Pattern constructor
     * @param	pattern a string representing the pattern
     * 			ie: ART\#TIT\#ALB
     */
    Pattern(string pattern);
    ~Pattern();
    /**
     * @brief Parse the pattern
     * @return #SUCCESS if succeeded, #FAILURE otherwise
     *
     */
    int parse();
    /**
     * @brief get the next pattern
     * @param token a pointer to a string where the next token will be stored
     * @return SUCCESS is succeded, FAILURE otherwise
     */
    int next(string* token);
    /**
     * @brief Restart the iterator at the beginning
     */
    void reset();
private:
    void tokenize(string str, string delimiters);
    string pattern;
    vector<string> tokens;
    vector<string>::iterator it;

};

#endif
