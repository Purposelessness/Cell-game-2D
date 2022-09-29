#ifndef GAME_UTILITY_IDENTIFIED_H_
#define GAME_UTILITY_IDENTIFIED_H_

#include "TypeIdentifier.h"

class Identified {
public:
    Identified() = default;
    [[nodiscard]] int getId() const;

protected:
    template<typename T>
    explicit Identified(T* t) {
        id = TypeIdentifier<T>::getId();
    }

protected:
    int id;
};

#endif //GAME_UTILITY_IDENTIFIED_H_