/**
 *
 *       @file  sqladapter.h
 *
 *      @brief  Abstract class for sql adapter
 *
 *    @version  1.0
 *       @date  17.06.2011 18:52:44
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#ifndef _SQL_ADAPTER_H_
#define _SQL_ADAPTER_H_

#include <iostream>
using namespace std;
class SqlAdapter{
	public:
		inline SqlAdapter(){};
		inline ~SqlAdapter(){};
	private:
		virtual int openDatabase(string databaseName) = 0;
		virtual void closeDatabase() = 0;
		virtual int executeQuery(string) = 0;
		virtual int executeSelect(string) = 0;
		virtual int fetchRow() = 0;
		virtual void freeResult() = 0;
		virtual const char* getStr(int x) = 0;
		virtual const char* getStr() = 0;
		virtual long getVal(const string& x) = 0;
		virtual long getVal() = 0;
		virtual long getVal(int x) = 0;
		virtual int getLastInsertedId() = 0;
};

#endif
