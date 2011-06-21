#include <id3tool/id3renamer.h>
#include <id3tool/pattern.h>
#include <defines/defines.h>
#include <browser/rbrowser.h>
#include <sqladapter/sqliteadapter.h>
#include <id3tool/id3tagger.h>

#include <set>
#include <iostream>

int main(int argc, char** argv){
	if(argc<2)
		return 0;
	/*
	Pattern p("ART#TIT");
	set<string> v;
	v.insert("mp3");
	p.parse();
	RBrowser t(argv[1],&p, &v);
	t.browse();
	SqliteAdapter adapter;

	adapter.openDatabase("test.db");
	string q ="create table t1 (t1key INTEGER PRIMARY KEY,data TEXT,num double,data2 TEXT);";
	adapter.executeQuery(q);
	q ="insert into t1 (data,num,data2) values ('This is sample data',4,'OK1');";
	adapter.executeQuery(q);
	q ="insert into t1 (data,num,data2) values ('Sample data 2',5,'OK2');";
	adapter.executeQuery(q);
	q="select data,num,data2 from t1;";
	adapter.executeSelect(q);
	while (adapter.fetch_row()==SUCCESS){
		string name;
		string name2;
		name = adapter.getStr();
		long num = adapter.getVal();
		name2 = adapter.getStr();
		cout<<"User#"<<num<<" : "<<name.c_str()<<" : "<<name2.c_str()<<endl;
	}
	adapter.closeDatabase();
	*/
	Id3Tagger tagger(argv[1]);
	tagger.tagAlbum("My album");
	tagger.tagArtist("Benoit Daccache");
	tagger.tagTitle("the song");
	tagger.tagYear("2012");



	return 1;
}

