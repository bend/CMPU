/**
 *
 *       @file  tbrowser.cpp
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  15.06.2011 16:02:57
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <browser/tbrowser.h>

TBrowser::TBrowser(string path, Pattern *pattern, set<string> *ext ): Browser(path) {
    this->ext = ext;
    this->pattern = pattern;
}

TBrowser::~TBrowser() {}

int TBrowser::apply(string str) {
    int period = str.find_last_of(".");
    string e = str.substr(period + 1);

    if(ext->find(e) != ext->end()) {
        Id3Tagger tag(str, this->pattern);
        return tag.apply();
    }

    return SUCCESS;
}



