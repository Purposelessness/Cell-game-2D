#ifndef GAME_VIEW_LOGVIEWMESSSAGE_H_
#define GAME_VIEW_LOGVIEWMESSSAGE_H_

#include "../Engine/View/ViewMessage.h"

struct LogViewMessage : public ViewMessage {
    explicit LogViewMessage(std::string message) : message(std::move(message)) {}

    std::string message;

    [[nodiscard]] std::string toString() const override {
        return message;
    }
};

#endif //GAME_VIEW_LOGVIEWMESSSAGE_H_