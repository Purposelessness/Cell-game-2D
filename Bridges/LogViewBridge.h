#ifndef GAME_BRIDGES_LOGVIEWBRIDGE_H_
#define GAME_BRIDGES_LOGVIEWBRIDGE_H_

#include <type_traits>

#include "../Utility/Log.h"
#include "../View/LogViewMesssage.h"
#include "../Utility/IDisposable.h"

template<typename T>
concept TLogRenderer = requires(T t) {
    t.update(std::declval<LogViewMessage>());
};

template<TLogRenderer T>
class LogViewBridge : public IDisposable {
public:
    explicit LogViewBridge(std::shared_ptr<T> renderer);
    ~LogViewBridge() override;

    void react(const LogEventMessage& message);

private:
    std::shared_ptr<T> _renderer;
};

template<TLogRenderer T>
LogViewBridge<T>::LogViewBridge(std::shared_ptr<T> renderer) : _renderer(renderer) {
    Log::instance().event_handler.template add(this, &LogViewBridge<T>::react);
}

template<TLogRenderer T>
LogViewBridge<T>::~LogViewBridge() {
    Log::instance().event_handler.template remove(this, &LogViewBridge<T>::react);
}

template<TLogRenderer T>
void LogViewBridge<T>::react(const LogEventMessage& message) {
    _renderer->update(LogViewMessage{message.message});
}

#endif //GAME_BRIDGES_LOGVIEWBRIDGE_H_