#include "Logger.h"

#include <memory>

#include "SubLoggers.h"

Logger& Logger::operator<<(const LogMessage& message) {
    this->operator()(message);
    return *this;
}

void Logger::operator()(std::string message, Logger::Level level) {
    this->operator()(LogMessage{std::move(message), level});
}

void Logger::operator()(const LogMessage& message) {
    std::string mes = levelToString(message.level) + ": " + message.message;
    _messages.emplace_back(mes);
    event_handler(LogMessage{std::move(mes), message.level});
}

Logger& Logger::instance() {
    static Logger log;
    return log;
}

std::vector<std::string>& Logger::messages() {
    return _messages;
}

SubLogger& Logger::logger(Logger::Level level) {
    return *_loggers[level];
}

Logger::Logger() {
    for (int i = 0; i < kLevelCount; ++i) {
        _loggers[i] = std::make_unique<SubLogger>(kLevels[i]);
    }
}

