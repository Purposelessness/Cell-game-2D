#include "gtest/gtest.h"

#include "../../Utility/EventHandler.h"

TEST(EventHandler, LambdaExpressions) {
    EventHandler<std::string, std::string> event_handler;
    std::vector<std::string> result;
    auto lambda = [&result](std::string s1, std::string s2) -> void {
        std::string s = s1 + " and " + s2;
        result.emplace_back(s);
    };
    event_handler += lambda;
    event_handler("test", "google");
    auto lambda2 = [&result](const std::string& s1, const std::string& s2) -> void {
        std::string s = s1 + " and " + s2 + " const";
        result.emplace_back(s);
    };
    event_handler += lambda2;
    event_handler("second", "game");
    event_handler -= lambda;
    event_handler("third", "lol");
    std::vector<std::string>
        answer{"test and google", "second and game", "second and game const", "third and lol const"};
    EXPECT_EQ(answer, result);
}

std::vector<int> vec;

void t1(int a, int b) {
    vec.emplace_back(a);
    vec.emplace_back(b);
}

void t2(const int& a, const int& b) {
    vec.emplace_back(a);
    vec.emplace_back(b);
}

TEST(EventHandler, StaticFunctions) {
    vec.clear();
    EventHandler<int, int> event_handler;
    event_handler += t1;
    event_handler += t2;
    event_handler(4, 3);
    event_handler -= t1;
    event_handler(5, 6);
    std::vector<int> ans{4, 3, 4, 3, 5, 6};
    EXPECT_EQ(vec, ans);
}

class T1 {
public:
    void t(int a, int b) {
        vec.emplace_back(a);
        vec.emplace_back(b);
    }
};

class T2 {
public:
    void t(int a, int b) {
        vec.emplace_back(a);
        vec.emplace_back(b);
        vec.emplace_back(x);
    }

    int x = 199;
};

TEST(EventHandler, MemberFunctions) {
    vec.clear();
    EventHandler<int, int> event_handler;
    T1 t1;
    T2 t2;
    event_handler.add(&t1, &T1::t);
    event_handler.add(&t2, &T2::t);
    event_handler(1, 2);
    t2.x = 10;
    event_handler(3, 4);
    event_handler.remove(&t2, &T2::t);
    event_handler(5, 6);
    std::vector<int> ans{1, 2, 1, 2, 199, 3, 4, 3, 4, 10, 5, 6};
    EXPECT_EQ(vec, ans);
}

std::vector<std::string> str_ans;

void printStr1(const std::string& s, const std::string& s2) {
    str_ans.emplace_back(s);
    str_ans.emplace_back(s2);
}

void printStr2(std::string s, std::string s2) {
    str_ans.emplace_back(s);
    str_ans.emplace_back(s2);
}

class A {
public:
    void test(std::string s, std::string s2) {
        str_ans.emplace_back(s);
        str_ans.emplace_back(s2);
    }
};

TEST(EventHandler, All) {
    EventHandler<std::string, std::string> event_handler;
    auto lambda = [&str_ans = str_ans](std::string s, std::string s2) {
        str_ans.emplace_back(s);
        str_ans.emplace_back(s2);
    };
    A a;
    event_handler += printStr1;
    event_handler += printStr2;
    event_handler += lambda;
    event_handler.add(&a, &A::test);
    event_handler("aboba", "boboba");
    event_handler -= printStr1;
    event_handler("aaaaa", "bbbbb");
    event_handler -= printStr2;
    event_handler("ZZZ", "VVV");
    event_handler -= lambda;
    event_handler("one", "two");
    event_handler.remove(&a, &A::test);
    event_handler("three", "four");

    std::vector<std::string> ans =
        {"aboba", "boboba", "aboba", "boboba", "aboba", "boboba", "aboba", "boboba", "aaaaa", "bbbbb", "aaaaa", "bbbbb",
         "aaaaa", "bbbbb", "ZZZ", "VVV",
         "ZZZ", "VVV", "one", "two"};
    EXPECT_EQ(ans, str_ans);
}