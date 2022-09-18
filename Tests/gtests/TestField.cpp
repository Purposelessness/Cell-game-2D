#include "gtest/gtest.h"
#include <iostream>

#include "../../Objects/Map/Field.h"

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
        _hello_event = std::make_shared<HelloEvent>();
        _bye_event = std::make_shared<ByeEvent>();
    }

    std::shared_ptr<HelloEvent> _hello_event;
    std::shared_ptr<ByeEvent> _bye_event;

    Field _f_1;
    Field _f_2;
};

TEST_F(TestField, Size) {
    int w, h;

    Field f_3{20, 15};
    f_3.getSize(w, h);
    EXPECT_EQ(w, 20);
    EXPECT_EQ(h, 15);

    Field f_4{-100, -100};
    f_4.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(h, 0);

    Field f_5{0, 20};
    f_5.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(h, 0);
}

TEST_F(TestField, CopyConstructor) {
    int w, h;
    _f_1 = Field{-10, 0};
    Field f_4{_f_1};
    f_4.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(w, 0);

    _f_1 = Field{-100, -100};
    Field f_5{_f_1};
    f_5.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(w, 0);

    _f_1 = Field{25, 35};
    _f_1.setCellEvent(0, 0, _hello_event);

    Field f_3{_f_1};
    f_3.getSize(w, h);
    EXPECT_EQ(w, 25);
    EXPECT_EQ(h, 35);
    EXPECT_EQ(_f_1.getCell(0, 0), f_3.getCell(0, 0));
    f_3.setCellEvent(0, 0, _bye_event);
    EXPECT_NE(_f_1.getCell(0, 0), f_3.getCell(0, 0));
}

TEST_F(TestField, CopyOperator) {
    int w, h;
    _f_1 = Field{-10, 0};
    Field f_4{};
    f_4 = _f_1;
    f_4.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(w, 0);

    _f_1 = Field{-100, -100};
    Field f_5{};
    f_5 = _f_1;
    f_5.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(w, 0);

    _f_1 = Field{25, 35};
    _f_1.setCellEvent(0, 0, _hello_event);

    Field f_3{};
    f_3 = _f_1;
    f_3.getSize(w, h);
    EXPECT_EQ(w, 25);
    EXPECT_EQ(h, 35);
    EXPECT_EQ(_f_1.getCell(0, 0), f_3.getCell(0, 0));
    f_3.setCellEvent(0, 0, _bye_event);
    EXPECT_NE(_f_1.getCell(0, 0), f_3.getCell(0, 0));
}

TEST_F(TestField, MoveConstructor) {
    int w_1, h_1;
    int w_2, h_2;

    _f_1 = Field{30, 40};
    _f_1.setCellEvent(0, 0, _hello_event);
    Field f_3{std::move(_f_1)};

    _f_1.getSize(w_1, h_1);
    f_3.getSize(w_2, h_2);
    EXPECT_EQ(w_1, 0);
    EXPECT_EQ(h_1, 0);
    EXPECT_EQ(w_2, 30);
    EXPECT_EQ(h_2, 40);
    EXPECT_EQ(_f_1.getCell(0, 0), Cell{});
    Cell c{};
    c.changeEvent(_hello_event);
    EXPECT_EQ(f_3.getCell(0, 0), c);

    _f_1 = Field{-20, 40};
    _f_1.setCellEvent(0, 0, _hello_event);
    Field f_4{std::move(_f_1)};

    _f_1.getSize(w_1, h_1);
    f_4.getSize(w_2, h_2);
    EXPECT_EQ(w_1, 0);
    EXPECT_EQ(h_1, 0);
    EXPECT_EQ(w_2, 0);
    EXPECT_EQ(h_2, 0);
    EXPECT_EQ(_f_1.getCell(0, 0), Cell{});
    EXPECT_NE(f_4.getCell(0, 0), c);
}

TEST_F(TestField, MoveOperator) {
    int w_1, h_1;
    int w_2, h_2;

    _f_1 = Field{30, 40};
    _f_1.setCellEvent(0, 0, _hello_event);
    Field f_3{};
    f_3 = std::move(_f_1);

    _f_1.getSize(w_1, h_1);
    f_3.getSize(w_2, h_2);
    EXPECT_EQ(w_1, 0);
    EXPECT_EQ(h_1, 0);
    EXPECT_EQ(w_2, 30);
    EXPECT_EQ(h_2, 40);
    EXPECT_EQ(_f_1.getCell(0, 0), Cell{});
    Cell c{};
    c.changeEvent(_hello_event);
    EXPECT_EQ(f_3.getCell(0, 0), c);

    _f_1 = Field{-20, 40};
    _f_1.setCellEvent(0, 0, _hello_event);
    Field f_4{};
    f_4 = std::move(_f_1);

    _f_1.getSize(w_1, h_1);
    f_4.getSize(w_2, h_2);
    EXPECT_EQ(w_1, 0);
    EXPECT_EQ(h_1, 0);
    EXPECT_EQ(w_2, 0);
    EXPECT_EQ(h_2, 0);
    EXPECT_EQ(_f_1.getCell(0, 0), Cell{});
    EXPECT_NE(f_4.getCell(0, 0), c);
}
