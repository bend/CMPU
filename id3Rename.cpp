/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11.06.2011 19:58:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ben D. (BD), dbapps2@gmail.com
 *        Company:  dbapps
 *
 * =====================================================================================
 */

#include <id3/tag.h>
#include <iostream>

using namespace std;


int main(int argc, char** argv){
	if(argc<2)
		puts("please provide filename");
	ID3_Tag myTag;
	myTag.Link(argv[1],ID3TT_ALL);
	ID3_Frame* myFrame = NULL;
	char *newName= new char[2048];
	myFrame= myTag.Find(ID3FID_LEADARTIST);
	if(myFrame!=0){
		char* artist = new char[1024];
		myFrame->Field(ID3FN_TEXT).Get(artist,1024);
		strncat(newName,artist,strlen(artist));
		strncat(newName," - ",3);
	}

	myFrame= myTag.Find(ID3FID_TITLE);
	
	if(myFrame!=0){
		char* title = new char[1024];
		myFrame->Field(ID3FN_TEXT).Get(title,1024);
		strncat(newName,title,strlen(title));
	}
	string pathName = argv[1];
	int period = pathName.find_last_of(".");
	string ext = pathName.substr(period);
	strcat(newName,ext.c_str());
	int result= rename( argv[1] , newName );
	if ( result == 0 )
		puts ( "File successfully renamed" );
	else
		perror( "Error renaming file" );
}
