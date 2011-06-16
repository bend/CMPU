
#include "id3Rename.h"
#include "pattern.h"
#include "defines.h"
#include "rbrowser.h"
#include <set>
using namespace std;
int main(int argc, char** argv){
	if(argc<2)
		return 0;
	Pattern p("ART#TIT");
	set<string> v;
	v.insert("mp3");
	p.parse();
	RBrowser t(argv[1],&p, &v);
	t.browse();


	return 1;
}
