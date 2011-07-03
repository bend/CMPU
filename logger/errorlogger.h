/**
 *
 *       @file  errorlogger.h
 *
 *      @brief  Error logger : singleton
 *
 *    @version  1.0
 *       @date  23.06.2011 15:32:36
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef _ERROR_LOGGER_H_
#define _ERROR_LOGGER_H_
#include <defines/logger.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <execinfo.h>
using namespace std;
class ErrorLogger{
	public:
		static void log( string, string var1="");
		static void  close();
	private:
		static ErrorLogger *singleton;
		static ofstream fout; 
		static void logBackTrace();
	protected:
		ErrorLogger();




};
#endif
