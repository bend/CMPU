/**
 *
 *       @file  testsqliteadapter.cpp
 *
 *      @brief  Test file for SqliteAdapter
 *
 *    @version  1.0
 *       @date  03.07.2011 09:37:47
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <tests/testsqliteadapter.h>

void testSqliteAdapter(){
	SqliteAdapter adapter;
	adapter.openDatabase(DB_SQL);
	assert(	adapter.executeQuery("CREATE TABLE Test( \
		id INTEGER PRIMARY KEY, \
		name TEXT);") == SUCCESS);
	assert(	adapter.executeQuery("CREATE TABLE Test( \
		id INTEGER PRIMARY KEY, \
		name TEXT);") == FAILURE);
	assert( adapter.executeQuery("INSERT INTO Test(name) \
		VALUES ('Ben');") == SUCCESS);
	assert( adapter.getLastInsertedId() == 1);
	assert( adapter.executeQuery("INSERT INTO Test(name) \
		VALUES ('Ben2');") == SUCCESS);
	assert( adapter.getLastInsertedId() == 2);
	assert( adapter.executeSelect("Select id, name From Test;") == SUCCESS);
	assert(adapter.fetchRow() == SUCCESS);
	long id = adapter.getVal();
	string name = adapter.getStr();
	assert(id==1);
	assert(name=="Ben");
	assert(adapter.fetchRow() == SUCCESS);
	id = adapter.getVal();
	name = adapter.getStr();
	assert(id==2);
	assert(name=="Ben2");
	assert(adapter.fetchRow() == FAILURE);
	adapter.freeResult();
	adapter.closeDatabase();
}

