#include "Log.h"

void Log::operator()(std::string message, Log::Level level) {
    this->operator()(LogEventMessage{std::move(message), level});
}

void Log::operator()(const LogEventMessage& message) {
    std::string mes = levelToString(message.level) + ": " + message.message;
    _messages.emplace_back(mes);
    event_handler(LogEventMessage{std::move(mes), message.level});
}

Log& Log::instance() {
    static Log log;
    return log;
}

std::vector<std::string>& Log::messages() {
    return _messages;
}
