#ifndef GAME_ECSLIB_COMPONENTS_TYPEIDENTIFIER_H_
#define GAME_ECSLIB_COMPONENTS_TYPEIDENTIFIER_H_

#include "Concept.h"

class CommonTypeInfo {
public:
    static int length;
};

template<TComponent T>
class TypeIdentifier : public CommonTypeInfo {
public:
    static void setup() {
        if (_id == -1)
            _id = length++;
    }

    static int getId() {
        return _id;
    }

private:
    static int _id;
};

template<TComponent T>
int TypeIdentifier<T>::_id = -1;

#endif //GAME_ECSLIB_COMPONENTS_TYPEIDENTIFIER_H_