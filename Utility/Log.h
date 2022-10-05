#ifndef GAME_UTILITY_LOG_H_
#define GAME_UTILITY_LOG_H_

#include <string>
#include <vector>

#include "EventHandler.h"

struct LogEventMessage;

class Log {
public:
    enum Level {
        Info,
        Warning,
        Error
    };

    static Log& instance();

    void operator()(std::string message, Level level = Info);
    void operator()(const LogEventMessage& message);

    std::vector<std::string>& messages();
    EventHandler<LogEventMessage> event_handler;

private:
    static inline std::string levelToString(Level level) {
        switch (level) {
            case Warning:
                return "[Warning]";
            case Error:
                return "[Error]";
            case Info:
            default:
                return "[Info]";
        }
    }

    std::vector<std::string> _messages;
};

struct LogEventMessage {
    std::string message;
    Log::Level level;
};

#endif //GAME_UTILITY_LOG_H_