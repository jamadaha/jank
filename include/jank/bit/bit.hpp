#ifndef JANK_BIT
#define JANK_BIT

#include <cstdint>
#include <cassert>
namespace jank::bit {
inline int lsb(uint16_t x) {
#if defined(__GNUC__)
    return __builtin_ctz(x);
#else
#error
#endif
}

inline int lsb(uint32_t x) {
#if defined(__GNUC__)
    return __builtin_ctzl(x);
#else
#error
#endif
}

inline int lsb(uint64_t x) {
#if defined(__GNUC__)
    return __builtin_ctzll(x);
#else
#error
#endif
}

inline int msb(uint16_t x) {
#if defined(__GNUC__)
    assert(sizeof(unsigned int) == 4);
    return 31 ^ __builtin_clz(x);
#else
#error
#endif
}

inline int msb(uint32_t x) {
#if defined(__GNUC__)
    assert(sizeof(unsigned long) == 8);
    return 63 ^ __builtin_clzl(x);
#else
#error
#endif
}

inline int msb(uint64_t x) {
#if defined(__GNUC__)
    assert(sizeof(unsigned long long) == 8);
    return 63 ^ __builtin_clzll(x);
#else
#error
#endif
}

inline int popcount(uint16_t x) {
#if defined(__GNUC__)
    return __builtin_popcount(x);
#else
#error
#endif
}

inline int popcount(uint32_t x) {
#if defined(__GNUC__)
    return __builtin_popcountl(x);
#else
#error
#endif
}

inline int popcount(uint64_t x) {
#if defined(__GNUC__)
    return __builtin_popcountll(x);
#else
#error
#endif
}
} // namespace jank::bit

#endif
