#ifndef JANK_BIT_TEST
#define JANK_BIT_TEST

#include <doctest/doctest.h>
#include <jank/bit/bit.hpp>

namespace jank::bit {

TEST_SUITE("lsb") {
    TEST_CASE("16bit") {
        uint16_t numbers[4] = {1, 2, 3, 4};
        int expected[4] = {0, 1, 0, 2};
        for (int i = 0; i < 4; i++)
            REQUIRE(lsb(numbers[i]) == expected[i]);
    }
    TEST_CASE("32bit") {
        uint32_t numbers[4] = {1, 2, 3, 4};
        int expected[4] = {0, 1, 0, 2};
        for (int i = 0; i < 4; i++)
            REQUIRE(lsb(numbers[i]) == expected[i]);
    }
    TEST_CASE("64bit") {
        uint64_t numbers[4] = {1, 2, 3, 4};
        int expected[4] = {0, 1, 0, 2};
        for (int i = 0; i < 4; i++)
            REQUIRE(lsb(numbers[i]) == expected[i]);
    }
}
TEST_SUITE("lsb_pop") {
    TEST_CASE("16bit") {
        uint16_t numbers[4] = {1, 2, 3, 4};
        int expected_lsb[4] = {0, 1, 0, 2};
        int expected_result[4] = {0, 0, 2, 0};
        for (int i = 0; i < 4; i++) {
            REQUIRE(lsb_pop(numbers[i]) == expected_lsb[i]);
            REQUIRE(numbers[i] == expected_result[i]);
        }
    }
    TEST_CASE("32bit") {
        uint32_t numbers[4] = {1, 2, 3, 4};
        int expected_lsb[4] = {0, 1, 0, 2};
        int expected_result[4] = {0, 0, 2, 0};
        for (int i = 0; i < 4; i++) {
            REQUIRE(lsb_pop(numbers[i]) == expected_lsb[i]);
            REQUIRE(numbers[i] == expected_result[i]);
        }
    }
    TEST_CASE("64bit") {
        uint64_t numbers[4] = {1, 2, 3, 4};
        int expected_lsb[4] = {0, 1, 0, 2};
        int expected_result[4] = {0, 0, 2, 0};
        for (int i = 0; i < 4; i++) {
            REQUIRE(lsb_pop(numbers[i]) == expected_lsb[i]);
            REQUIRE(numbers[i] == expected_result[i]);
        }
    }
}
TEST_SUITE("msb") {
    TEST_CASE("16bit") {
        uint16_t numbers[4] = {1, 2, 3, 4};
        int expected[4] = {0, 1, 1, 2};
        for (int i = 0; i < 4; i++)
            REQUIRE(msb(numbers[i]) == expected[i]);
    }
    TEST_CASE("32bit") {
        uint32_t numbers[4] = {1, 2, 3, 4};
        int expected[4] = {0, 1, 1, 2};
        for (int i = 0; i < 4; i++)
            REQUIRE(msb(numbers[i]) == expected[i]);
    }
    TEST_CASE("64bit") {
        uint64_t numbers[4] = {1, 2, 3, 4};
        int expected[4] = {0, 1, 1, 2};
        for (int i = 0; i < 4; i++)
            REQUIRE(msb(numbers[i]) == expected[i]);
    }
}
TEST_SUITE("popcount") {
    TEST_CASE("16bit") {
        uint16_t numbers[4] = {1, 2, 3, 4};
        int expected[4] = {1, 1, 2, 1};
        for (int i = 0; i < 4; i++)
            REQUIRE(popcount(numbers[i]) == expected[i]);
    }
    TEST_CASE("32bit") {
        uint32_t numbers[4] = {1, 2, 3, 4};
        int expected[4] = {1, 1, 2, 1};
        for (int i = 0; i < 4; i++)
            REQUIRE(popcount(numbers[i]) == expected[i]);
    }
    TEST_CASE("64bit") {
        uint64_t numbers[4] = {1, 2, 3, 4};
        int expected[4] = {1, 1, 2, 1};
        for (int i = 0; i < 4; i++)
            REQUIRE(popcount(numbers[i]) == expected[i]);
    }
}
} // namespace jank::bit
#endif
