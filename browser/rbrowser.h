/**
 *
 *       @file  test.h
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  15.06.2011 16:02:58
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#ifndef _RBROWSER_H_
#define _RBROWSER_H_
#include <browser/browser.h>
#include <id3tool/id3renamer.h>
#include <utils/pattern.h>

#include <iostream>
#include <set>
using namespace std;
class RBrowser: public Browser {
public:
    RBrowser(string test, Pattern* pattern, set<string> *vect);
    ~RBrowser();
private:
    virtual int apply(string str);
    Pattern* pattern;
    set<string> *ext;

};

#endif
