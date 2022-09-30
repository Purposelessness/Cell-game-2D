#include "gtest/gtest.h"

#include "../../Engine/View/ViewRenderer.h"
#include "../../Engine/View/ViewSystem.h"

struct GameViewMessage : public ViewMessage {};

std::vector<std::string> test;

class GameViewRenderer {
public:
    explicit GameViewRenderer(int value) : value(value) {}

    template<TViewMessage T>
    void update(const T& message) {
        std::string out = "GameViewRenderer.update() : " + std::to_string(value) + " " + message.information + '\n';
        test.emplace_back(out);
    }

//    void update(const ViewMessage& message) {
//    }
//
//    void update(const GameViewMessage& message) {
//    }

    int value = 0;
};

template<>
void GameViewRenderer::update<GameViewMessage>(const GameViewMessage& message) {
    std::string out = "GameViewRenderer.GAME_update() : " + std::to_string(value) + " " + message.information + '\n';
    test.emplace_back(out);
}

class ViewRenderer {
public:
    template<TViewMessage T>
    void update(const T& message) {
        std::string out = "ViewRenderer.update() : " + std::to_string(value) + " " + message.information + '\n';
        test.emplace_back(out);
    }

    int value = 0;
};

TEST(ViewSystemTest, AddRemoveRenderers) {
    ViewSystem<GameViewRenderer, ViewRenderer> view_system;

    view_system.addRenderer<GameViewRenderer>(10);
    view_system.addRenderer<ViewRenderer>();

    GameViewMessage game_view_message{"gaming boy"};
    ViewMessage view_message{"simple dimple"};

    view_system.render(game_view_message);
    view_system.render(view_message);

    view_system.removeRenderer<ViewRenderer>();
    view_system.render(game_view_message);

    EXPECT_EQ(test[0], "GameViewRenderer.GAME_update() : 10 gaming boy\n");
    EXPECT_EQ(test[1], "ViewRenderer.update() : 0 gaming boy\n");
    EXPECT_EQ(test[2], "GameViewRenderer.update() : 10 simple dimple\n");
    EXPECT_EQ(test[3], "ViewRenderer.update() : 0 simple dimple\n");
    EXPECT_EQ(test[4], "GameViewRenderer.GAME_update() : 10 gaming boy\n");
}
