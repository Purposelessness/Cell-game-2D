#ifndef GAME_TESTOBSERVER_H
#define GAME_TESTOBSERVER_H


#include "../Observer/EventHandler.h"

namespace Test {

    enum TestEventType {
        TestEventFirst,
        TestEventSecond
    };

    class FirstEventMessage : public IEventMessage {
    public:
        std::string getName() override;
        int getValue() override;
    };

    class SecondEventMessage : public IEventMessage {
    public:
        std::string getName() override;
        int getValue() override;
    };

    class TestEventManager : public EventHandler {
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

}


#endif //GAME_TESTOBSERVER_H