#ifndef GAME_ICONTROLLER_H
#define GAME_ICONTROLLER_H


struct KeyInfo;

class IController {
public:
    virtual void process(const KeyInfo &inputMessage) = 0;
};


#endif //GAME_ICONTROLLER_H
