#define LOGGING

#ifndef GAME_UTILITY_LOG_LOG_H_
#define GAME_UTILITY_LOG_LOG_H_

#include "Logger.h"
#include "SubLoggers.h"

#define LOG Logger::instance()

#define LOG_TRACE Logger::instance().logger(Logger::Trace)
#define LOG_INFO Logger::instance().logger(Logger::Info)
#define LOG_WARNING Logger::instance().logger(Logger::Warning)
#define LOG_ERROR Logger::instance().logger(Logger::Error)

#ifdef LOGGING
#define LOG_TRACE_F(x) Logger::instance()(x, Logger::Trace)
#define LOG_INFO_F(x) Logger::instance()(x, Logger::Info)
#define LOG_WARNING_F(x) Logger::instance()(x, Logger::Warning)
#define LOG_ERROR_F(x) Logger::instance()(x, Logger::Error)
#else
#define LOG_TRACE_F(x)
#define LOG_INFO_F(x)
#define LOG_WARNING_F(x)
#define LOG_ERROR_F(x)
#endif

#endif //GAME_UTILITY_LOG_LOG_H_