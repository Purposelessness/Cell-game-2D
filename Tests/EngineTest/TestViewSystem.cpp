#include "gtest/gtest.h"

#include "../../Engine/View/ViewRenderer.h"
#include "../../Engine/View/ViewSystem.h"

struct GameViewMessage : public ViewMessage {};

std::vector<std::string> test;

class GameViewRenderer {
public:
    void update(const ViewMessage& message) {
        std::string out = "GameViewRenderer.update() : " + message.information + '\n';
        test.emplace_back(out);
    }

    void update(const GameViewMessage& message) {
        std::string out = "GameViewRenderer.GAME_update() : " + message.information + '\n';
        test.emplace_back(out);
    }
};

class ViewRenderer {
public:
    void update(const ViewMessage& message) {
        std::string out = "ViewRenderer.update() : " + message.information + '\n';
        test.emplace_back(out);
    }
};

TEST(ViewSystemTest, Concepts) {
    auto game_view_renderer = new GameViewRenderer;
    auto view_renderer = new ViewRenderer;

    ViewSystem view_system(game_view_renderer, view_renderer);
    GameViewMessage game_view_message{"gaming boy"};
    ViewMessage view_message{"simple dimple"};

    view_system.render(game_view_message);
    view_system.render(view_message);

    EXPECT_EQ(test[0], "GameViewRenderer.GAME_update() : gaming boy\n");
    EXPECT_EQ(test[1], "ViewRenderer.update() : gaming boy\n");
    EXPECT_EQ(test[2], "GameViewRenderer.update() : simple dimple\n");
    EXPECT_EQ(test[3], "ViewRenderer.update() : simple dimple\n");
}
