/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12.06.2011 23:50:12
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Ben D. (BD), dbapps2@gmail.com
 *        Company:  dbapps
 *
 * =====================================================================================
 */

#include "Id3Rename.h"

int main(int argc, char** argv){
	if(argc<2)
		return 0;
	Id3Rename id(argv[1]);
	id.apply();
	return 1;
}
