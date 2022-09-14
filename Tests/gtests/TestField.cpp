#include "gtest/gtest.h"
#include <iostream>

#include "../../Objects/Map/Field.h"
#include "../../Events/IEvent.h"

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

TEST_F(TestField, CopyOperator) {
    int w, h;
    f1 = Field{-10, 0};
    Field f4{};
    f4 = f1;
    f4.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(w, 0);

    f1 = Field{-100, -100};
    Field f5{};
    f5 = f1;
    f5.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(w, 0);

    f1 = Field{25, 35};
    f1.setCellEvent(0, 0, helloEvent);

    Field f3{};
    f3 = f1;
    f3.getSize(w, h);
    EXPECT_EQ(w, 25);
    EXPECT_EQ(h, 35);
    EXPECT_EQ(f1.getCell(0, 0), f3.getCell(0, 0));
    f3.setCellEvent(0, 0, byeEvent);
    EXPECT_NE(f1.getCell(0, 0), f3.getCell(0, 0));
}

TEST_F(TestField, MoveConstructor) {
    int w1, h1;
    int w2, h2;

    f1 = Field{30, 40};
    f1.setCellEvent(0, 0, helloEvent);
    Field f3{std::move(f1)};

    f1.getSize(w1, h1);
    f3.getSize(w2, h2);
    EXPECT_EQ(w1, 0);
    EXPECT_EQ(h1, 0);
    EXPECT_EQ(w2, 30);
    EXPECT_EQ(h2, 40);
    EXPECT_EQ(f1.getCell(0, 0), Cell{});
    Cell c{};
    c.changeEvent(helloEvent);
    EXPECT_EQ(f3.getCell(0, 0), c);

    f1 = Field{-20, 40};
    f1.setCellEvent(0, 0, helloEvent);
    Field f4{std::move(f1)};

    f1.getSize(w1, h1);
    f4.getSize(w2, h2);
    EXPECT_EQ(w1, 0);
    EXPECT_EQ(h1, 0);
    EXPECT_EQ(w2, 0);
    EXPECT_EQ(h2, 0);
    EXPECT_EQ(f1.getCell(0, 0), Cell{});
    EXPECT_NE(f4.getCell(0, 0), c);
}

TEST_F(TestField, MoveOperator) {
    int w1, h1;
    int w2, h2;

    f1 = Field{30, 40};
    f1.setCellEvent(0, 0, helloEvent);
    Field f3{};
    f3 = std::move(f1);

    f1.getSize(w1, h1);
    f3.getSize(w2, h2);
    EXPECT_EQ(w1, 0);
    EXPECT_EQ(h1, 0);
    EXPECT_EQ(w2, 30);
    EXPECT_EQ(h2, 40);
    EXPECT_EQ(f1.getCell(0, 0), Cell{});
    Cell c{};
    c.changeEvent(helloEvent);
    EXPECT_EQ(f3.getCell(0, 0), c);


    f1 = Field{-20, 40};
    f1.setCellEvent(0, 0, helloEvent);
    Field f4{};
    f4 = std::move(f1);

    f1.getSize(w1, h1);
    f4.getSize(w2, h2);
    EXPECT_EQ(w1, 0);
    EXPECT_EQ(h1, 0);
    EXPECT_EQ(w2, 0);
    EXPECT_EQ(h2, 0);
    EXPECT_EQ(f1.getCell(0, 0), Cell{});
    EXPECT_NE(f4.getCell(0, 0), c);
}
