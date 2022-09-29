#ifndef GAME_UTILITY_TYPEIDENTIFIER_H_
#define GAME_UTILITY_TYPEIDENTIFIER_H_

class CommonTypeInfo {
protected:
    static int length;
};

template<typename T>
class TypeIdentifier : public CommonTypeInfo {
public:
    static int getId() {
        if (_id == -1)
            _id = length++;
        return _id;
    }

private:
    static int _id;
};

template<typename T>
int TypeIdentifier<T>::_id = -1;

#endif //GAME_UTILITY_TYPEIDENTIFIER_H_