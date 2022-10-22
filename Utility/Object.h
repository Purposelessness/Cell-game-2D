#ifndef GAME_UTILITY_OBJECT_H_
#define GAME_UTILITY_OBJECT_H_

#include "Identified.h"
#include "IConvertibleToString.h"
#include "IDisposable.h"

class Object;

template<typename T>
concept TObject = std::is_base_of_v<Object, T>;

class Object : public Identified, public IConvertibleToString, public IDisposable {
public:
    Object();

    explicit operator std::string() const override;

protected:
    template<TObject T>
    explicit Object(T* t) : Identified(t) {}
};

#endif //GAME_UTILITY_OBJECT_H_