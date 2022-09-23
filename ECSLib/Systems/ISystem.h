#ifndef GAME_ECSLIB_SYSTEMS_ISYSTEM_H_
#define GAME_ECSLIB_SYSTEMS_ISYSTEM_H_

class ISystem {
public:
    virtual void tick() = 0;
};

#endif //GAME_ECSLIB_SYSTEMS_ISYSTEM_H_