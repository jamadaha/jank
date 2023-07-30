#ifndef JANK_BIT
#define JANK_BIT

#include <cassert>
#include <cstdint>

/**
* NOTE: These are not tested on 32-bit architecture, and might(likely) not work as intended
*/ 

namespace jank::bit {
/**
* @brief Returns the number of trailing 0-bits in x, starting from the least significant bit
* @param x A non-zero unsigned 16 bit number
* @example ...01 -> 0 
* @example ...10 -> 1
*/
inline int lsb(uint16_t x) {
#if defined(__GNUC__)
    return __builtin_ctz(x);
#else
#error
#endif
}

/**
* @brief Returns the number of trailing 0-bits in x, starting from the least significant bit
* @param x A non-zero unsigned 32 bit number
* @example ...01 -> 0 
* @example ...10 -> 1
*/
inline int lsb(uint32_t x) {
#if defined(__GNUC__)
    return __builtin_ctzl(x);
#else
#error
#endif
}

/**
* @brief Returns the number of trailing 0-bits in x, starting from the least significant bit
* @param x A non-zero unsigned 64 bit number
* @example ...01 -> 0 
* @example ...10 -> 1
*/
inline int lsb(uint64_t x) {
#if defined(__GNUC__)
    return __builtin_ctzll(x);
#else
#error
#endif
}

/**
* @brief Returns the number of leading 0-bits in x, starting from the most significant bit
* @param x A non-zero unsigned 16 bit number
* @example 10... -> 0 
* @example 01... -> 1
*/
inline int msb(uint16_t x) {
#if defined(__GNUC__)
    static_assert(sizeof(unsigned int) == 4);
    return 31 ^ __builtin_clz(x);
#else
#error
#endif
}

/**
* @brief Returns the number of leading 0-bits in x, starting from the most significant bit
* @param x A non-zero unsigned 32 bit number
* @example 10... -> 0 
* @example 01... -> 1
*/
inline int msb(uint32_t x) {
#if defined(__GNUC__)
#if __x86_64__ || __ppc64__
    static_assert(sizeof(unsigned long) == 8);
    return 63 ^ __builtin_clzl(x);
#else
    assert(sizeof(unsigned long) == 4);
    return 31 ^ __builtin_clzl(x);
#endif
#else
#error
#endif
}

/**
* @brief Returns the number of leading 0-bits in x, starting from the most significant bit
* @param x A non-zero unsigned 64 bit number
* @example 10... -> 0 
* @example 01... -> 1
*/
inline int msb(uint64_t x) {
#if defined(__GNUC__)
    static_assert(sizeof(unsigned long long) == 8);
    return 63 ^ __builtin_clzll(x);
#else
#error
#endif
}

/**
* @brief Returns the number of 1-bits in x
* @param x An unsigned 16 bit number
* @example 100... -> 1
* @example 110... -> 2
*/
inline int popcount(uint16_t x) {
#if defined(__GNUC__)
    return __builtin_popcount(x);
#else
#error
#endif
}

/**
* @brief Returns the number of 1-bits in x
* @param x An unsigned 32 bit number
* @example 100... -> 1
* @example 110... -> 2
*/
inline int popcount(uint32_t x) {
#if defined(__GNUC__)
    return __builtin_popcountl(x);
#else
#error
#endif
}

/**
* @brief Returns the number of 1-bits in x
* @param x An unsigned 64 bit number
* @example 100... -> 1
* @example 110... -> 2
*/
inline int popcount(uint64_t x) {
#if defined(__GNUC__)
    return __builtin_popcountll(x);
#else
#error
#endif
}
} // namespace jank::bit

#endif
