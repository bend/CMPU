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
#include <sqladapter/sqladapter.h>
#include <defines/defines.h>
#include <logger/errorlogger.h>

#include <sqlite3.h>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;

class SqliteAdapter: public SqlAdapter {
public:
    SqliteAdapter();
    ~SqliteAdapter();
    int openDatabase(string databaseName);
    void closeDatabase();
    int executeQuery(string query);
    int executeSelect(string query);
    int fetchRow();
    void freeResult();
    const char* getStr(int x);
    const char* getStr();
    long getVal(const string& x);
    long getVal();
    long getVal(int x);
    virtual int getLastInsertedId();
private:
    int readFile(string path, string* returnVal);

    sqlite3 *db;
    sqlite3_stmt *res;
    map<string, int> m_nmap;
    string m_tmpstr;
    string m_last_query;
    int m_num_cols;
    int rowcount;
    int cache_rc;
    int m_row_count;
    bool row;
    bool cache_rc_valid;
};
#endif
