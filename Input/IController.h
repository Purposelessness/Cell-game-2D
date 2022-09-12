#ifndef GAME_ICONTROLLER_H
#define GAME_ICONTROLLER_H


namespace Engine {
    struct InputMessage;

    class IController {
    public:
        virtual void process(const InputMessage &inputMessage) = 0;
    };

}


#endif //GAME_ICONTROLLER_H
