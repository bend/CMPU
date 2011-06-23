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
#include <iostream>
using namespace std;
class ErrorLogger{
	public:
		static ErrorLogger* getInstance();
		static void  close();
	private:
		static ErrorLogger *singleton;
	protected:
		ErrorLogger();




};
#endif
