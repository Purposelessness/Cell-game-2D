#include "Observer.h"

namespace Test {

    void FirstEventMessage::invoke() const {
        printf("First event message\n");
    }

    std::string FirstEventMessage::getName() {
        return "FirstEventMessage";
    }

    void SecondEventMessage::invoke() const {
        printf("Second event message\n");
    }

    std::string SecondEventMessage::getName() {
        return "SecondEventMessage";
    }

    void FirstEventListener::update(IEventMessage *e) {
        printf("FirstEventListener updated\n");
        e->invoke();
    }

    void SecondEventListener::update(IEventMessage *e) {
        printf("SecondEventListener updated\n");
        e->invoke();
    }

    void testObserver() {
        TestEventManager manager;
        FirstEventListener firstEventListener;
        SecondEventListener secondEventListener;
        manager.subscribe(&firstEventListener);
        manager.subscribe(&secondEventListener);

        FirstEventMessage firstMessage;
        manager.notify(&firstMessage);

        manager.unsubscribe(&firstEventListener);
        SecondEventMessage secondMessage;
        manager.notify(&secondMessage);
    }

} // Test