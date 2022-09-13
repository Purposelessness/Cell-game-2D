#include "gtest/gtest.h"
#include <iostream>

#include "../Objects/Map/Field.h"
#include "../Events/IEvent.h"

class HelloEvent : public IEvent {
public:
    void invoke() override {}
};

class ByeEvent : public IEvent {
public:
    void invoke() override {}
};

class TestField : public ::testing::Test {
protected:
    void SetUp() override {
        helloEvent = std::make_shared<HelloEvent>();
        byeEvent = std::make_shared<ByeEvent>();
    }

    std::shared_ptr<HelloEvent> helloEvent;
    std::shared_ptr<ByeEvent> byeEvent;

    Field f1;
    Field f2;
};

TEST_F(TestField, Size) {
    int w, h;

    Field f3{20, 15};
    f3.getSize(w, h);
    EXPECT_EQ(w, 20);
    EXPECT_EQ(h, 15);

    Field f4{-100, -100};
    f4.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(h, 0);

    Field f5{0, 20};
    f5.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(h, 0);
}

TEST_F(TestField, CopyConstructor) {
    int w, h;
    f1 = Field{-10, 0};
    Field f4{f1};
    f4.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(w, 0);

    f1 = Field{-100, -100};
    Field f5{f1};
    f5.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(w, 0);

    f1 = Field{25, 35};
    f1.setCellEvent(0, 0, helloEvent);

    Field f3{f1};
    f3.getSize(w, h);
    EXPECT_EQ(w, 25);
    EXPECT_EQ(h, 35);
    EXPECT_EQ(f1.getCell(0, 0), f3.getCell(0, 0));
    f3.setCellEvent(0, 0, byeEvent);
    EXPECT_NE(f1.getCell(0, 0), f3.getCell(0, 0));
}
