#ifndef GAME_OBSERVER_LOGOBSERVER_H_
#define GAME_OBSERVER_LOGOBSERVER_H_

#include <type_traits>

#include "../Utility/Log/Logger.h"
#include "../Utility/IDisposable.h"
#include "../Message/LogInfoMesssage.h"

template<typename T>
concept TLogObserverClient = requires(T t) {
    t << std::declval<LogInfoMessage>();
};

template<TLogObserverClient... Ts>
class LogObserver : public IDisposable {
public:
    explicit LogObserver(std::shared_ptr<Ts>... clients);
    ~LogObserver() override;

    void react(const LogMessage& message);

private:
    std::tuple<std::shared_ptr<Ts>...> _clients;
};

template<TLogObserverClient... Ts>
LogObserver<Ts...>::LogObserver(std::shared_ptr<Ts>... clients) : _clients(std::make_tuple(std::move(clients)...)) {
    Logger::instance().event_handler.template add(this, &LogObserver<Ts...>::react);
}

template<TLogObserverClient... Ts>
LogObserver<Ts...>::~LogObserver() {
    Logger::instance().event_handler.template remove(this, &LogObserver<Ts...>::react);
}

template<TLogObserverClient... Ts>
void LogObserver<Ts...>::react(const LogMessage& message) {
    auto view_message = LogInfoMessage{message.message};
    Tuple::forEach(_clients, [&view_message]<TLogObserverClient T>(std::shared_ptr<T>& client) {
        *client << view_message;
    });
}

#endif //GAME_OBSERVER_LOGOBSERVER_H_