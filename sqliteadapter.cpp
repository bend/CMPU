/**
 *
 *       @file  sqliteadapter.cpp
 *
 *      @brief  The sqlite wrapper
 *
 *    @version  1.0
 *       @date  17.06.2011 19:19:37
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include "sqliteadapter.h"

SqliteAdapter::SqliteAdapter():SqlAdapter(){}
SqliteAdapter::~SqliteAdapter(){}
int SqliteAdapter::openDatabase(char* databaseName){
	int rc;
	rc = sqlite3_open(databaseName, &(this->db));
	if( rc ){
		cerr<<"Can't open database: "<< sqlite3_errmsg(this->db)<<endl;
		sqlite3_close(db);
		return FAILURE;
	}
	return SUCCESS;
}

void SqliteAdapter::closeDatabase(){
	sqlite3_close(this->db);
}

int SqliteAdapter::executeQuery(char* query,int (*callback)(void*,int,char**,char**)){
	return SUCCESS;
}
