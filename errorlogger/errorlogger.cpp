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

ErrorLogger::ErrorLogger(){}

ErrorLogger* ErrorLogger::getInstance(){
	if(singleton == NULL)
		singleton = new ErrorLogger;
	return singleton;
}

void ErrorLogger::close(){
	if(singleton != NULL){
		delete singleton;
		singleton = NULL;
	}
}
