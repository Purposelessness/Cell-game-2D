#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H


#include "../Observer/EventManager.h"

namespace Test {

    class FirstEventMessage : public IEventMessage {
    public:
        void invoke() const override;
        std::string getName() override;
    };

    class SecondEventMessage : public IEventMessage {
    public:
        void invoke() const override;
        std::string getName() override;
    };

    class TestEventManager : public EventManager {
    };

    class FirstEventListener : public EventListener {
    public:
        void update(IEventMessage *e) override;
    };

    class SecondEventListener : public EventListener {
    public:
        void update(IEventMessage *e) override;
    };

    void testObserver();

} // Test


#endif //GAME_OBSERVER_H