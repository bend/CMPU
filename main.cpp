
#include "id3Rename.h"
#include "pattern.h"
#include "defines.h"
#include "rbrowser.h"
int main(int argc, char** argv){
	if(argc<0)
		return 0;
	Pattern *p = new Pattern("TIT#ART");
	p->parse();
	RBrowser t(argv[1],p);
	t.browse();


	return 1;
}
