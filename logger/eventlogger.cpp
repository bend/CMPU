/**
 *
 *       @file  eventlogger.cpp
 *
 *      @brief  Event logger : singleton
 *
 *    @version  1.0
 *       @date  23.06.2011 15:32:36
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <logger/eventlogger.h>

EventLogger *EventLogger::singleton = NULL;
ofstream EventLogger::fout;

EventLogger::EventLogger() {
    fout.open(EVENT_LOG_PATH, ios::app);
}

void EventLogger::log(string message, string var1) {
    if(singleton == NULL)
        singleton = new EventLogger;

    fout << message << var1 << endl;
}

void EventLogger::close() {
    fout.close();

    if(singleton != NULL) {
        delete singleton;
        singleton = NULL;
    }
}

