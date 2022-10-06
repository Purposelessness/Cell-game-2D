#ifndef GAME_VIEW_CONSOLEVIEW_CONSOLEWINDOWTAB_H_
#define GAME_VIEW_CONSOLEVIEW_CONSOLEWINDOWTAB_H_

#include <memory>

#include "../../Datatypes/Size.h"

class ConsoleWindowObserver;

class ConsoleWindowTab {
public:
    explicit ConsoleWindowTab(const Size& size = Size{}, const Size& margin = Size{}, ConsoleWindowObserver* observer = nullptr);
    explicit ConsoleWindowTab(ConsoleWindowObserver* observer);

    void setObserver(ConsoleWindowObserver* observer);

    void resize(const Size& new_size);
    void resize(int width, int height);
    void setMargin(const Size& new_margin);
    void setMargin(int x, int y);

    [[nodiscard]] Size getSize() const;
    [[nodiscard]] Size getMargin() const;

protected:
    Size size;
    Size margin;
    ConsoleWindowObserver* observer;
};

#endif //GAME_VIEW_CONSOLEVIEW_CONSOLEWINDOWTAB_H_