#ifndef GAME_UTILITY_LOG_SUBLOGGERS_H_
#define GAME_UTILITY_LOG_SUBLOGGERS_H_

#include "Logger.h"

struct SubLogger {
    explicit SubLogger(Logger::Level level) : level(level) {}

    inline SubLogger& operator<<(const std::string& message) {
        Logger::instance()(LogEventMessage{message, level});
        return *this;
    }

    inline void operator()(const std::string& message) {
        Logger::instance()(LogEventMessage{message, level});
    }

    Logger::Level level = Logger::Trace;
};

#endif //GAME_UTILITY_LOG_SUBLOGGERS_H_
