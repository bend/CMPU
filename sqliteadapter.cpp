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

#include <sqliteadapter.h>

SqliteAdapter::SqliteAdapter():SqlAdapter(){}
SqliteAdapter::~SqliteAdapter(){}
int SqliteAdapter::openDatabase(string databaseName){
	int rc;
	rc = sqlite3_open(databaseName.c_str(), &(this->db));
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

int SqliteAdapter::executeQuery(string query){
	const char *s = NULL;
	int rc = sqlite3_prepare(this->db, query.c_str(), query.size(), &res, &s);
	if (rc != SQLITE_OK){
		cerr<<"execute: prepare query failed"<<sqlite3_errmsg(this->db)<<endl;
		return FAILURE;
	}
	if (!res){
		cerr<<"execute: query failed"<<sqlite3_errmsg(this->db)<<endl;
		return FAILURE;
	}
	rc = sqlite3_step(res); // execute
	sqlite3_finalize(res); // deallocate statement
	res = NULL;
	switch (rc){
		case SQLITE_BUSY:
			cerr<<"execute: database busy"<<endl;
			return FAILURE;
		case SQLITE_DONE:
		case SQLITE_ROW:
			return SUCCESS;
		case SQLITE_ERROR:
			cerr<<sqlite3_errmsg(this->db)<<endl;
			return SUCCESS;
		case SQLITE_MISUSE:
			cerr<<"execute: database misuse"<<endl;
			return FAILURE;
	}
	cerr<<"execute: unknown result code"<<endl;
	return FAILURE;	
}

int SqliteAdapter::executeSelect(string query){
	if(!res){
		const char *s = NULL;
		int rc = sqlite3_prepare(this->db, query.c_str(), query.size(), &res, &s);
		if (rc != SQLITE_OK){
			cerr<<"get_result: prepare query failed"<<sqlite3_errmsg(this->db)<<endl;
			return FAILURE;
		}
		if (!res){
			cerr<<"get_result: query failed"<<endl;
			return FAILURE;
		}
		// get column names from result
		{
			int i = 0;
			do{
				const char *p = sqlite3_column_name(res, i);
				if (!p)
					break;
				m_nmap[p] = ++i;
			} while (true);
			m_num_cols = i;
		}
		cache_rc = sqlite3_step(res);
		cache_rc_valid = true;
		m_row_count = (cache_rc == SQLITE_ROW) ? 1 : 0;
	}
	return SUCCESS;
}

int SqliteAdapter::fetch_row(){
	row = false;
	rowcount = 0;
	int rc = cache_rc_valid ? cache_rc : sqlite3_step(res); 
	cache_rc_valid = false;
	switch (rc){
		case SQLITE_BUSY:
			cout<<"execute: database busy"<<endl;
			return FAILURE;
		case SQLITE_DONE:
			return FAILURE;
		case SQLITE_ROW:
			row = true;
			return SUCCESS;
		case SQLITE_ERROR:
			cerr<<sqlite3_errmsg(this-> db)<<endl;
			return FAILURE;
		case SQLITE_MISUSE:
			cerr<<"execute: database misuse"<<endl;
			return FAILURE;
	}
	cerr<<"execute: unknown result code"<<endl;
	return FAILURE;
}

const char* SqliteAdapter::getStr(int x){
	if(res && row && x < sqlite3_column_count(res) ){
		const unsigned char *tmp = sqlite3_column_text(res, x);
		return tmp ? (const char *)tmp : "";
	}
	return "";
}

const char* SqliteAdapter::getStr(){
	return this->getStr(rowcount++);
}

long SqliteAdapter::getVal(const string& x){
	int index = m_nmap[x] - 1;
	if (index >= 0)
		return getVal(index);
	cerr<<"Column name lookup failure: " <<x<<endl;
	return 0;
}

long SqliteAdapter::getVal(int x){
	if (res && row){
		return sqlite3_column_int(res, x);
	}
	return 0;
}

long SqliteAdapter::getVal(){
	return getVal(rowcount++);
}
