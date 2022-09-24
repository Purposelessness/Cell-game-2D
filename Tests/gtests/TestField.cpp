#include "gtest/gtest.h"
#include <iostream>

#include "../../Objects/Field/Field.h"
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
    TestField() : null_field(Field{0, 0}) {}

    void SetUp() override {
        hello_event = std::make_shared<HelloEvent>();
        bye_event = std::make_shared<ByeEvent>();
    }

    std::shared_ptr<HelloEvent> hello_event;
    std::shared_ptr<ByeEvent> bye_event;

    Field f_1;
    Field f_2;
    Field null_field;
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
    EXPECT_EQ(f_4, null_field);

    Field f_5{0, 20};
    f_5.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(h, 0);
    EXPECT_EQ(f_5, null_field);
}

TEST_F(TestField, CopyConstructor) {
    int w, h;
    f_1 = Field{-10, 0};
    Field f_4{f_1};
    f_4.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(f_1, null_field);

    f_1 = Field{-100, -100};
    Field f_5{f_1};
    f_5.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(f_1, null_field);

    f_1 = Field{25, 35};
    f_1.setCellEvent(0, 0, hello_event);

    Field f_3{f_1};
    EXPECT_EQ(f_3, f_1);
    EXPECT_EQ(f_1.getCell(0, 0), f_3.getCell(0, 0));
    f_3.setCellEvent(0, 0, bye_event);
    EXPECT_NE(f_3, f_1);
    EXPECT_NE(f_1.getCell(0, 0), f_3.getCell(0, 0));
}

TEST_F(TestField, CopyOperator) {
    int w, h;
    f_1 = Field{-10, 0};
    Field f_4{};
    f_4 = f_1;
    f_4.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(h, 0);
    EXPECT_EQ(f_4, null_field);

    f_1 = Field{-100, -100};
    Field f_5{};
    f_5 = f_1;
    f_5.getSize(w, h);
    EXPECT_EQ(w, 0);
    EXPECT_EQ(h, 0);
    EXPECT_EQ(f_5, null_field);

    f_1 = Field{25, 35};
    f_1.setCellEvent(0, 0, hello_event);

    Field f_3{};
    f_3 = f_1;
    EXPECT_EQ(f_3, f_1);
    f_3.getSize(w, h);
    EXPECT_EQ(w, 25);
    EXPECT_EQ(h, 35);
    EXPECT_EQ(f_1.getCell(0, 0), f_3.getCell(0, 0));
    f_3.setCellEvent(0, 0, bye_event);
    EXPECT_NE(f_3, f_1);
    EXPECT_NE(f_1.getCell(0, 0), f_3.getCell(0, 0));
}

TEST_F(TestField, MoveConstructor) {
    int w_1, h_1;
    int w_2, h_2;

    f_1 = Field{30, 40};
    f_1.setCellEvent(5, 5, hello_event);
    Field f_3{std::move(f_1)};
    EXPECT_EQ(f_1, null_field);

    f_1.getSize(w_1, h_1);
    f_3.getSize(w_2, h_2);
    EXPECT_EQ(w_1, 0);
    EXPECT_EQ(h_1, 0);
    EXPECT_EQ(w_2, 30);
    EXPECT_EQ(h_2, 40);
    Cell c{};
    c.changeEvent(hello_event);
    EXPECT_EQ(f_3.getCell(5, 5), c);
    EXPECT_NE(f_3.getCell(0, 0), c);

    f_1 = Field{-20, 40};
    f_1.setCellEvent(0, 0, hello_event);
    Field f_4{std::move(f_1)};
    EXPECT_EQ(f_1, null_field);
    EXPECT_EQ(f_4, null_field);

    f_1.getSize(w_1, h_1);
    f_4.getSize(w_2, h_2);
    EXPECT_EQ(w_1, 0);
    EXPECT_EQ(h_1, 0);
    EXPECT_EQ(w_2, 0);
    EXPECT_EQ(h_2, 0);
    EXPECT_EQ(f_1.getCell(0, 0), Cell{});
    EXPECT_NE(f_4.getCell(0, 0), c);
}

TEST_F(TestField, MoveOperator) {
    int w_1, h_1;
    int w_2, h_2;

    f_1 = Field{30, 40};
    f_1.setCellEvent(0, 0, hello_event);
    Field f_3{};
    f_3 = std::move(f_1);
    EXPECT_EQ(f_1, null_field);

    f_1.getSize(w_1, h_1);
    f_3.getSize(w_2, h_2);
    EXPECT_EQ(w_1, 0);
    EXPECT_EQ(h_1, 0);
    EXPECT_EQ(w_2, 30);
    EXPECT_EQ(h_2, 40);
    EXPECT_EQ(f_1.getCell(0, 0), Cell{});
    Cell c{};
    c.changeEvent(hello_event);
    EXPECT_EQ(f_3.getCell(0, 0), c);

    f_1 = Field{-20, 40};
    f_1.setCellEvent(0, 0, hello_event);
    Field f_4{};
    f_4 = std::move(f_1);
    EXPECT_EQ(f_1, null_field);
    EXPECT_EQ(f_4, null_field);

    f_1.getSize(w_1, h_1);
    f_4.getSize(w_2, h_2);
    EXPECT_EQ(w_1, 0);
    EXPECT_EQ(h_1, 0);
    EXPECT_EQ(w_2, 0);
    EXPECT_EQ(h_2, 0);
    EXPECT_EQ(f_1.getCell(0, 0), Cell{});
    EXPECT_NE(f_4.getCell(0, 0), c);
}
