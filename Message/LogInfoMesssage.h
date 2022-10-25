#ifndef GAME_MESSAGE_LOGINFOMESSSAGE_H_
#define GAME_MESSAGE_LOGINFOMESSSAGE_H_

#include "../Engine/Utility/InfoMessage.h"

struct LogInfoMessage : public InfoMessage {
    explicit LogInfoMessage(std::string message) : message(std::move(message)) {}

    std::string message;

    explicit operator std::string() const override {
        return message;
    }
};

#endif //GAME_MESSAGE_LOGINFOMESSSAGE_H_