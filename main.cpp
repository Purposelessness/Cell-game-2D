#include <cstdio>
#include "Core/Delegate.h"

class Test {
public:
    void a(int b) {
        printf("%d", b);
    }
};

int main() {
    Test t;
    Core::Delegate d;
    d.connect(&t, &Test::a);
    d(10);
    d(t);
}