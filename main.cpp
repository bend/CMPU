
#include "id3Rename.h"
#include "pattern.h"
#include "defines.h"
int main(int argc, char** argv){
	if(argc<0)
		return 0;
	Pattern *p = new Pattern("TIT");
	Id3Rename id(argv[1], p);
	id.apply();
	return 1;
}
