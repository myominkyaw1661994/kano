#pragma once

#include "../defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

//Disable debug and trace for release builds.
#if KRELEASE == 1
    #define LOG_DEBUG_ENABLED 0
    #define LOG_TRACE_ENABLED 0
#endif

typedef enum loglevel  {
    LOG_LEVEL_FETAL = 0, 
    LOG_LEVEL_ERROR = 1, 
    LOG_LEVEL_WARN = 2, 
    LOG_LEVEL_INFO = 3, 
    LOG_LEVEL_DEBUG = 4, 
    LOG_LEVEL_TRACE = 5, 
} loglevel;

b8 initialize_logging();
void shutdown_logging();

KAPI void log_output(loglevel level, const char* message, ...);

// log a fetal-level message
#define KFATEL(message, ...) log_output(LOG_LEVEL_FETAL, message, ##__VA_ARGS__);

#ifndef KERROR
    // log an error-level message
    #define KERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
    //log a warnning-level message
    #define KWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
    #define KWARN(message, ...);
#endif

#if LOG_INFO_ENABLED == 1
    //log a info-level message
    #define KINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
    #define KINFO(message, ...);
#endif

#if LOG_DEBUG_ENABLED == 1
    //log a debug-level message
    #define KDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
    #define KDEBUG(message, ...);
#endif

#if LOG_TRACE_ENABLED == 1
    //log trace-level message
    #define KTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
    #define KTRACE(message, ...);
#endif