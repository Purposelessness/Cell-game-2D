#ifndef GAME_UTILITY_OBJECT_H_
#define GAME_UTILITY_OBJECT_H_

#include "Identified.h"
#include "IConvertibleToString.h"

class Object;

template<typename T>
concept TObject = std::is_base_of_v<Object, T>;

class Object : public Identified, public IConvertibleToString {
public:
    Object();

    std::string toString() override;

protected:
    template<TObject T>
    explicit Object(T* t) : Identified(t) {}
};

#endif //GAME_UTILITY_OBJECT_H_