#ifndef GAME_UTILITY_LOG_LOGGER_H_
#define GAME_UTILITY_LOG_LOGGER_H_

#include <string>
#include <vector>

#include "../EventHandler.h"

struct LogEventMessage;
struct SubLogger;

class Logger {
public:
    enum Level {
        Trace = 0,
        Info = 1,
        Warning = 2,
        Error = 3
    };
    static constexpr int kLevelCount = 4;
    static constexpr std::array<Level, kLevelCount> kLevels = {Trace, Info, Warning, Error};

    static Logger& instance();

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    Logger& operator<<(const LogEventMessage& message);
    void operator()(std::string message, Level level = Info);
    void operator()(const LogEventMessage& message);

    std::vector<std::string>& messages();
    SubLogger& logger(Level level);
    EventHandler<LogEventMessage> event_handler;

private:
    Logger();

    static inline std::string levelToString(Level level) {
        switch (level) {
            case Warning:
                return "[Warning]";
            case Error:
                return "[Error]";
            case Info:
                return "[Info]";
            case Trace:
            default:
                return "[Trace]";
        }
    }

    std::array<std::unique_ptr<SubLogger>, kLevelCount> _loggers;
    std::vector<std::string> _messages;
};

struct LogEventMessage {
    std::string message;
    Logger::Level level;
};

#endif //GAME_UTILITY_LOG_LOGGER_H_