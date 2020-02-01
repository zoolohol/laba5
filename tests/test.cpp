//Copyright 2019 <LinkIvan333>

#include <gtest/gtest.h>
#include <iostream>
#include <stack2.hpp>
#include <stack1.hpp>


TEST(Example, EmptyTest) {
    stack1<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    EXPECT_EQ(4, a.head());
    a.pop();
    EXPECT_EQ(3, a.head());
    stack2<int> b;
    b.push_emplace(1, 2);
    b.push_emplace(3, 4);
    EXPECT_EQ(4, b.head());
}
