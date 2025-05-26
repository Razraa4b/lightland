#include <time.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "log.h"
#include "win32/console.h"

void _log(log_lvl lvl, const char* message, va_list args)
{
    const char* lvl_s;
    switch(lvl)
    {
        case DEBUG_LOG:
            lvl_s = "DEBUG";
            break;
        case INFO_LOG:
            lvl_s = "INFO";
            break;
        case WARN_LOG:
            lvl_s = "WARN";
            break;
        case ERROR_LOG:
            lvl_s = "ERROR";
            break;
        case CRIT_LOG:
            lvl_s = "CRIT";
            break;
        case FATAL_LOG:
            lvl_s = "FATAL";
            break;
    }
    
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);

    struct tm *timeinfo = localtime(&ts.tv_sec);
    char time_s[80];
    strftime(time_s, 80, "%a %b %d %H:%M:%S", timeinfo);

    // Print time
    printf("%s.%03ld ", time_s, ts.tv_nsec / 1000000);
    
    switch(lvl)
    {
        case DEBUG_LOG:
            set_console_color(CONSOLE_COLOR_CYAN, CONSOLE_COLOR_BLACK);
            break;
        case INFO_LOG:
            set_console_color(CONSOLE_COLOR_GREEN, CONSOLE_COLOR_BLACK);
            break;
        case WARN_LOG:
            set_console_color(CONSOLE_COLOR_YELLOW, CONSOLE_COLOR_BLACK);
            break;
        case ERROR_LOG:
            set_console_color(CONSOLE_COLOR_RED, CONSOLE_COLOR_BLACK);
            break;
        case CRIT_LOG:
            set_console_color(CONSOLE_COLOR_LIGHT_RED, CONSOLE_COLOR_BLACK);
            break;
        case FATAL_LOG:
            set_console_color(CONSOLE_COLOR_LIGHT_RED, CONSOLE_COLOR_BLACK);
            break;
    }
    // Print log level
    printf("[%s]", lvl_s);
    set_console_color(CONSOLE_COLOR_WHITE, CONSOLE_COLOR_BLACK);

    // Print log message
    printf(": ");
    vprintf(message, args);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void ldebug(const char* format, ...) 
{
    va_list args;
    va_start(args, format);
    _log(Debug, format, args);
    va_end(args);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void linfo(const char* format, ...) 
{
    va_list args;
    va_start(args, format);
    _log(Info, format, args);
    va_end(args);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void lwarn(const char* format, ...) 
{
    va_list args;
    va_start(args, format);
    _log(Warn, format, args);
    va_end(args);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void lerror(const char* format, ...) 
{
    va_list args;
    va_start(args, format);
    _log(Error, format, args);
    va_end(args);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void lcrit(const char* format, ...) 
{
    va_list args;
    va_start(args, format);
    _log(Crit, format, args);
    va_end(args);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void lfatal(const char* format, ...) 
{
    va_list args;
    va_start(args, format);
    _log(Fatal, format, args);
    va_end(args);
}
