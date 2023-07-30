#ifndef JANK_BIT_TEST
#define JANK_BIT_TEST

#include <doctest/doctest.h>
#include <jank/bit/bit.hpp>

namespace jank::bit {

TEST_SUITE("lsb") {
    TEST_CASE("16bit") {
        SUBCASE("passing") {
            uint16_t numbers[4] = {1, 2, 3, 4};
            int expected[4] = {0, 1, 0, 2};
            for (int i = 0; i < 4; i++)
                REQUIRE(lsb(numbers[i]) == expected[i]);
        }
    }
    TEST_CASE("32bit") {
        SUBCASE("passing") {
            uint32_t numbers[4] = {1, 2, 3, 4};
            int expected[4] = {0, 1, 0, 2};
            for (int i = 0; i < 4; i++)
                REQUIRE(lsb(numbers[i]) == expected[i]);
        }
    }
    TEST_CASE("64bit") {
        SUBCASE("passing") {
            uint64_t numbers[4] = {1, 2, 3, 4};
            int expected[4] = {0, 1, 0, 2};
            for (int i = 0; i < 4; i++)
                REQUIRE(lsb(numbers[i]) == expected[i]);
        }
    }
}
TEST_SUITE("msb") {
    TEST_CASE("16bit") {
        SUBCASE("passing") {
            uint16_t numbers[4] = {1, 2, 3, 4};
            int expected[4] = {0, 1, 1, 2};
            for (int i = 0; i < 4; i++)
                REQUIRE(msb(numbers[i]) == expected[i]);
        }
    }
    TEST_CASE("32bit") {
        SUBCASE("passing") {
            uint32_t numbers[4] = {1, 2, 3, 4};
            int expected[4] = {0, 1, 1, 2};
            for (int i = 0; i < 4; i++)
                REQUIRE(msb(numbers[i]) == expected[i]);
        }
    }
    TEST_CASE("64bit") {
        SUBCASE("passing") {
            uint64_t numbers[4] = {1, 2, 3, 4};
            int expected[4] = {0, 1, 1, 2};
            for (int i = 0; i < 4; i++)
                REQUIRE(msb(numbers[i]) == expected[i]);
        }
    }
}
TEST_SUITE("popcount") {
    TEST_CASE("16bit") {
        SUBCASE("passing") {
            uint16_t numbers[4] = {1, 2, 3, 4};
            int expected[4] = {1, 1, 2, 1};
            for (int i = 0; i < 4; i++)
                REQUIRE(popcount(numbers[i]) == expected[i]);
        }
    }
    TEST_CASE("32bit") {
        SUBCASE("passing") {
            uint32_t numbers[4] = {1, 2, 3, 4};
            int expected[4] = {1, 1, 2, 1};
            for (int i = 0; i < 4; i++)
                REQUIRE(popcount(numbers[i]) == expected[i]);
        }
    }
    TEST_CASE("64bit") {
        SUBCASE("passing") {
            uint64_t numbers[4] = {1, 2, 3, 4};
            int expected[4] = {1, 1, 2, 1};
            for (int i = 0; i < 4; i++)
                REQUIRE(popcount(numbers[i]) == expected[i]);
        }
    }
}
} // namespace jank::bit
#endif
