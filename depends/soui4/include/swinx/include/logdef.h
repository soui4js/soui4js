#ifndef _LOG_DEF_H_
#define _LOG_DEF_H_

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

    enum LogPriority {
        SLOG_VERBOSE=0,
        /** Debug logging. Should typically be disabled for a release apk. */
        SLOG_DEBUG,
        /** Informational logging. Should typically be disabled for a release apk. */
        SLOG_INFO,
        /** Warning logging. For use with recoverable failures. */
        SLOG_WARN,
        /** Error logging. For use with unrecoverable failures. */
        SLOG_ERROR,
        /** Fatal logging. For use when aborting. */
        SLOG_FATAL,
    };

    typedef void (*SWinxLogCallback)(const char* pLogStr, int level);

    void WINAPI SetSwinxLogCallback(SWinxLogCallback cb,int level);

#ifdef __cplusplus
}
#endif //__cplusplus
#endif//_LOG_DEF_H_