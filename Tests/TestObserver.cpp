#include "TestObserver.h"

namespace Test {

    std::string FirstEventMessage::getName() {
        return "FirstEventMessage";
    }

    int FirstEventMessage::getValue() {
        return TestEventFirst;
    }

    std::string SecondEventMessage::getName() {
        return "SecondEventMessage";
    }

    int SecondEventMessage::getValue() {
        return TestEventSecond;
    }

    void FirstEventListener::update(IEventMessage *e) {
        printf("FirstEventListener updated\n");
        if (e->getValue() == TestEventFirst) {
            printf("First!\n");
        } else if (e->getValue() == TestEventSecond) {
            printf("Second!\n");
        }
    }

    void SecondEventListener::update(IEventMessage *e) {
        printf("SecondEventListener updated\n");
        if (e->getValue() == TestEventFirst) {
            printf("First!\n");
        } else if (e->getValue() == TestEventSecond) {
            printf("Second!\n");
        }
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

}
