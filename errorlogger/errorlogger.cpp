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

#include <errorlogger/errorlogger.h>

ErrorLogger *ErrorLogger::singleton = NULL;
ofstream ErrorLogger::fout;

ErrorLogger::ErrorLogger(){
	 fout.open(LOG_PATH,ios::app);
}

void ErrorLogger::log(string type, string message){
	if(singleton == NULL)
		singleton = new ErrorLogger;
	fout<<type<<" : "<<message<<endl;
}

void ErrorLogger::close(){
	fout.close();
	if(singleton != NULL){
		delete singleton;
		singleton = NULL;
	}
}
