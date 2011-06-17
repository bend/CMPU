/**
 *
 *       @file  sqliteadapter.h
 *
 *      @brief  The sqlite wrapper
 *
 *    @version  1.0
 *       @date  17.06.2011 19:19:48
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#ifndef _SQLITE_ADAPTER_H_
#define _SQLITE_ADAPTER_H_
#include "sqladapter.h"
#include "defines.h"

#include <sqlite3.h>

#include <iostream>
using namespace std;

class SqliteAdapter:public SqlAdapter{
	public:
		SqliteAdapter();
		~SqliteAdapter();
		virtual int openDatabase(char* databaseName);
		virtual void closeDatabase();
		virtual int createDatabase(char* name, char* inst);
		virtual int executeQuery(char* query,int (*callback)(void*,int,char**,char**));
	private:
		sqlite3 *db;
};

#endif
