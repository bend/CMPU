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
class SqlAdapter{
	public:
		inline SqlAdapter(){};
		inline ~SqlAdapter(){};
	private:
		virtual int openDatabase(char* databaseName) = 0;
		virtual void closeDatabase() = 0;
		virtual int createDatabase(char* name, char* inst) = 0;
		virtual int executeQuery(char* query,int (*callback)(void*,int,char**,char**)) = 0;



};

#endif
