#include "logger.h"


// TODO: tempoary
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

b8 initialize_logging(){
    return TRUE;
}
void shutdown_logging(){

}

KAPI void log_output(loglevel level, const char* message, ...){

    const char* level_string[6] = {"[FETAL]: ","[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};
    // b8 error = level < 2;

    char out_messgae[32000];
    memset(out_messgae, 0, sizeof(out_messgae));

    //pick the argument from message and all the way
    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(out_messgae, 32000, message, arg_ptr);
    va_end(arg_ptr);

    char out_messgae2[32000];
    sprintf(out_messgae2, "%s%s\n", level_string[level], out_messgae);
    
    // TODO: platform-specific output
    printf("%s", out_messgae2);

}