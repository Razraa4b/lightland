#ifndef LOG_H
#define LOG_H

#define DEBUG_LOG 0
#define INFO_LOG  1
#define WARN_LOG  2
#define ERROR_LOG 3
#define CRIT_LOG  4
#define FATAL_LOG 5

typedef enum
{
    Debug = DEBUG_LOG,
    Info  = INFO_LOG,
    Warn  = WARN_LOG,
    Error = ERROR_LOG,
    Crit  = CRIT_LOG,
    Fatal = FATAL_LOG
} log_lvl;

#ifdef __cplusplus
extern "C" {
#endif
void _log(log_lvl lvl, const char* message, ...);
void ldebug(const char* message, ...);
void linfo (const char* message, ...);
void lwarn (const char* message, ...);
void lerror(const char* message, ...);
void lcrit (const char* message, ...);
void lfatal(const char* message, ...);
#ifdef __cplusplus
}
#endif

#endif
