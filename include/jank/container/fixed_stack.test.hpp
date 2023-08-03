#ifndef JANK_FIXED_STACK_TEST
#define JANK_FIXED_STACK_TEST

#include "fixed_stack.hpp"
#include <doctest/doctest.h>

namespace jank::container {
TEST_SUITE("fixed_stack") {
    TEST_CASE("constructor") {
        fixed_stack<int, 0> stack;
        REQUIRE(stack.empty());
        REQUIRE_EQ(stack.size(), 0);
        REQUIRE_EQ(stack.max_size(), 0);
    }
    TEST_CASE("copy constructor") {
        fixed_stack<int, 3> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);

        fixed_stack<int, 3> oStack{stack};

        REQUIRE_EQ(oStack.size(), stack.size());
        REQUIRE_EQ(oStack.max_size(), stack.max_size());
        REQUIRE_EQ(oStack.top(), 3);
        oStack.pop();
        REQUIRE_EQ(oStack.top(), 2);
        oStack.pop();
        REQUIRE_EQ(oStack.top(), 1);
        oStack.pop();
        REQUIRE(oStack.empty());
    }
    TEST_CASE("copy assignement") {
        fixed_stack<int, 3> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);

        fixed_stack<int, 3> oStack = stack;

        REQUIRE_EQ(oStack.size(), stack.size());
        REQUIRE_EQ(oStack.max_size(), stack.max_size());
        REQUIRE_EQ(oStack.top(), 3);
        oStack.pop();
        REQUIRE_EQ(oStack.top(), 2);
        oStack.pop();
        REQUIRE_EQ(oStack.top(), 1);
        oStack.pop();
        REQUIRE(oStack.empty());
    }
    TEST_CASE("empty") {
        SUBCASE("0") {
            fixed_stack<int, 0> stack;
            REQUIRE(stack.empty());
        }
        SUBCASE("1") {
            fixed_stack<int, 1> stack;
            REQUIRE(stack.empty());
        }
        SUBCASE("non-empty") {
            fixed_stack<int, 1> stack;
            stack.push(0);
            REQUIRE(!stack.empty());
        }
    }
    TEST_CASE("size") {
        SUBCASE("0") {
            fixed_stack<int, 0> stack;
            REQUIRE_EQ(stack.size(), 0);
        }
        SUBCASE("1") {
            fixed_stack<int, 3> stack;
            stack.push(0);
            REQUIRE_EQ(stack.size(), 1);
        }
        SUBCASE("2") {
            fixed_stack<int, 3> stack;
            stack.push(0);
            stack.push(0);
            REQUIRE_EQ(stack.size(), 2);
        }
    }
    TEST_CASE("max_size") {
        SUBCASE("0") {
            fixed_stack<int, 0> stack;
            REQUIRE_EQ(stack.max_size(), 0);
        }
        SUBCASE("1") {
            fixed_stack<int, 1> stack;
            REQUIRE_EQ(stack.max_size(), 1);
        }
        SUBCASE("2") {
            fixed_stack<int, 2> stack;
            REQUIRE_EQ(stack.max_size(), 2);
        }
    }
    TEST_CASE("top") {
        SUBCASE("single element") {
            fixed_stack<int, 1> stack;
            stack.push(0);
            REQUIRE_EQ(stack.top(), 0);
        }
        SUBCASE("multiple elements") {
            fixed_stack<int, 2> stack;
            stack.push(0);
            stack.push(1);
            REQUIRE_EQ(stack.top(), 1);
        }
        SUBCASE("modification") {
            fixed_stack<int, 1> stack;
            stack.push(0);
            REQUIRE_EQ(stack.top(), 0);
            stack.top() = 1;
            REQUIRE_EQ(stack.top(), 1);
        }
    }
    TEST_CASE("const top") {
        SUBCASE("single element") {
            fixed_stack<int, 1> stack;
            stack.push(0);
            REQUIRE_EQ(stack.top(), 0);
        }
        SUBCASE("multiple elements") {
            fixed_stack<int, 2> stack;
            stack.push(0);
            stack.push(1);
            REQUIRE_EQ(stack.top(), 1);
        }
    }
    TEST_CASE("push") {
        fixed_stack<int, 3> stack;
        REQUIRE_EQ(stack.size(), 0);
        stack.push(0);
        REQUIRE_EQ(stack.size(), 1);
        REQUIRE_EQ(stack.top(), 0);
        stack.push(1);
        REQUIRE_EQ(stack.size(), 2);
        REQUIRE_EQ(stack.top(), 1);
    }
    TEST_CASE("pop") {
        fixed_stack<int, 3> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);
        REQUIRE_EQ(stack.size(), 3);
        REQUIRE_EQ(stack.top(), 3);
        stack.pop();
        REQUIRE_EQ(stack.size(), 2);
        REQUIRE_EQ(stack.top(), 2);
        stack.pop();
        REQUIRE_EQ(stack.size(), 1);
        REQUIRE_EQ(stack.top(), 1);
        stack.pop();
        REQUIRE_EQ(stack.size(), 0);
    }
}
} // namespace jank::container
#endif
