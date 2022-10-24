//#ifdef DEBUG

#ifndef GAME_UTILITY_LOG_LOG_H_
#define GAME_UTILITY_LOG_LOG_H_

#include "Logger.h"
#include "SubLoggers.h"

#define LOG Logger::instance()

#define LOG_TRACE Logger::instance().logger(Logger::Trace)
#define LOG_INFO Logger::instance().logger(Logger::Info)
#define LOG_WARNING Logger::instance().logger(Logger::Warning)
#define LOG_ERROR Logger::instance().logger(Logger::Error)

#endif //GAME_UTILITY_LOG_LOG_H_

//#endif