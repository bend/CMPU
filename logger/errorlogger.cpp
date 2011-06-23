/**
 *
 *       @file  errorlogger.cpp
 *
 *      @brief  Error logger : singleton
 *
 *    @version  1.0
 *       @date  23.06.2011 15:32:36
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <logger/errorlogger.h>

ErrorLogger *ErrorLogger::singleton = NULL;
ofstream ErrorLogger::fout;

ErrorLogger::ErrorLogger(){
	 fout.open(LOG_PATH,ios::app);
}

void ErrorLogger::log(string message,string var1){
	if(singleton == NULL)
		singleton = new ErrorLogger;
	fout<<message<<var1<<endl;
	logBackTrace();
}

void ErrorLogger::close(){
	fout.close();
	if(singleton != NULL){
		delete singleton;
		singleton = NULL;
	}
}

void ErrorLogger::logBackTrace(){
	void *array[10];
	size_t size;
	char **strings;
	size_t i;

	size = backtrace (array, 10);
	strings = backtrace_symbols (array, size);

	fout<<"Obtained "<<size<< " stack frames."<<endl;    
	for (i = 0; i < size; i++){
		fout<< strings[i]<<endl;
	}
	free (strings);
}

