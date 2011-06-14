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
#include "Pattern.h"
#include "Defines.h"
int main(int argc, char** argv){
	char token[MAX_TOK];
	if(argc<0)
		return 0;
	/*Id3Rename id(argv[1]);
	cout<<id.apply()<<endl;
	*/
	cout<<argv[0]<<endl;

	Pattern p("ART#TIT#GEN#YEAR#AZ#AAZEAZE");
	p.parse();
	while(p.next(token)!=EMPTY){
		cout<<token<<endl;
	}

	return 1;
}
