#ifndef GAME_UTILITY_LOG_LEVELS_H_
#define GAME_UTILITY_LOG_LEVELS_H_

#include <string>
#include "../IConvertibleToString.h"

namespace log {
    struct Level : public IConvertibleToString {
        inline explicit operator std::string() const override {
            return "Undefined";
        }

        inline virtual explicit operator int() const {
            return 0;
        }
    };

    struct Trace : public Level {
        inline explicit operator std::string() const override {
            return "Trace";
        }

        inline explicit operator int() const override {
            return 1;
        }
    };

    struct Info : public Level {
        inline explicit operator std::string() const override {
            return "Info";
        }

        inline explicit operator int() const override {
            return 2;
        }
    };

    struct Warning : public Level {
        inline explicit operator std::string() const override {
            return "Warning";
        }

        inline explicit operator int() const override {
            return 3;
        }
    };

    struct Error : public Level {
        inline explicit operator std::string() const override {
            return "Error";
        }

        inline explicit operator int() const override {
            return 4;
        }
    };
}

#endif //GAME_UTILITY_LOG_LEVELS_H_
