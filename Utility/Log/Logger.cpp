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
    if (!_extended_filtering && message.level < _filter_level) {
        return;
    } else if (_extended_filtering && !_levels_enabled[message.level]) {
        return;
    }
    std::string mes = levelToString(message.level) + ": " + message.message;
    _messages.emplace_back(mes);
    event_handler(LogMessage{std::move(mes), message.level});
}

Logger& Logger::instance() {
    static Logger log;
    return log;
}

void Logger::setFilterLevel(Logger::Level level) {
    _filter_level = level;
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

void Logger::enableExtendedFiltering() {
    _extended_filtering = true;
}

void Logger::disableExtendedFiltering() {
    _extended_filtering = false;
}

void Logger::enableFilterLevel(Level level) {
    if (!_extended_filtering) {
        this->operator()(LogMessage{"Extended filtering is disabled", Warning});
        return;
    }
    _levels_enabled[level] = true;
}

void Logger::disableFilterLevel(Level level) {
    if (!_extended_filtering) {
        this->operator()(LogMessage{"Extended filtering is disabled", Warning});
        return;
    }
    _levels_enabled[level] = false;
}
