#include "config.h"
#include "Core/MainApplication.h"

#define DEBUG

int main() {
    MainApplication a;
    return a.execute(kUpdateTimeMcsec);
}
