#include <id3tool/id3renamer.h>
#include <utils/pattern.h>
#include <defines/defines.h>
#include <defines/error.h>
#include <browser/rbrowser.h>
#include <browser/tbrowser.h>
#include <sqladapter/sqliteadapter.h>
#include <logger/errorlogger.h>
#include <library/librarymanager.h>

#include <set>
#include <iostream>

int main(int argc, char** argv){
	if(argc<2)
		return 0;
	/*
	Pattern p("ART#Benoit#ALB#My Album");
	set<string> v;
	v.insert("mp3");
	p.parse();

	TBrowser t(argv[1],&p, &v);
	t.browse();
	*/

	LibraryManager l("musicLib");
	//l.createLibrary();
	l.openLibrary();
	l.addAlbum("TESt", "This is an album");
	l.addArtist("TEST ART", "This is an artist very famous");
	l.addArtist("ART 2", "This 2 is an artist very famous");
	l.addArtist("ART 3", "This 3 is an artist very famous");
	l.closeLibrary();
	SqliteAdapter adapter;
	adapter.openDatabase("musicLib");
	adapter.executeSelect("Select name, details from Artist;");
	while (adapter.fetchRow()==SUCCESS){
		string name;
		string details;
		name = adapter.getStr();
		details = adapter.getStr();
		cout<<"Name "<<name<<"Details "<<details<<endl;
	}
	adapter.freeResult();
	adapter.executeSelect("Select name, details from Album;");
	while (adapter.fetchRow()==SUCCESS){
		string name;
		string details;
		name = adapter.getStr();
		details = adapter.getStr();
		cout<<"Name ALBUM"<<name<<"Details "<<details<<endl;
	}
	adapter.freeResult();

	adapter.openDatabase("test.db");
	string q ="create table t1 (t1key INTEGER PRIMARY KEY,data TEXT,num double,data2 TEXT);";
	adapter.executeQuery(q);
	q ="insert into t1 (data,num,data2) values ('This is sample data',4,'OK1');";
	adapter.executeQuery(q);
	q ="insert into t1 (data,num,data2) values ('Sample data 2',5,'OK2');";
	adapter.executeQuery(q);
	q="select data,num,data2 from t1;";
	adapter.executeSelect(q);
	while (adapter.fetchRow()==SUCCESS){
		string name;
		string name2;
		name = adapter.getStr();
		long num = adapter.getVal();
		name2 = adapter.getStr();
		cout<<"User#"<<num<<" : "<<name.c_str()<<" : "<<name2.c_str()<<endl;
	}
	adapter.closeDatabase();

	cout<<argv[0]<<endl;



	return 1;
}

