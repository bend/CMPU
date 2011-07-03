/**
 *
 *       @file  utils.cpp
 *
 *      @brief  Utils file
 *
 *    @version  1.0
 *       @date  03.07.2011 10:59:21
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#include <utils/utils.h>

string toString(int i){
	string s;
	stringstream out;
	out << i;
	s = out.str();
	return s;
}
