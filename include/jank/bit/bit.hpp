#ifndef JANK_BIT
#define JANK_BIT

namespace jank::bit {
inline int lsb(unsigned int x) {
#if defined(__GNUC__)
    return __builtin_ctz(x);
#else
    #error
#endif
}

inline int lsb(unsigned long x) {
#if defined(__GNUC__)
    return __builtin_ctzl(x);
#else
    #error
#endif
}

inline int lsb(unsigned long long x) {
#if defined(__GNUC__)
    return __builtin_ctzll(x);
#else
    #error
#endif
}

inline int msb(unsigned int x) {
#if defined(__GNUC__)
    return __builtin_clz(x);
#else
    #error
#endif
}

inline int msb(unsigned long x) {
#if defined(__GNUC__)
    return __builtin_clzl(x);
#else
    #error
#endif
}

inline int msb(unsigned long long x) {
#if defined(__GNUC__)
    return __builtin_clzll(x);
#else
    #error
#endif
}

inline int popcount(unsigned int x) {
#if defined(__GNUC__)
    return __builtin_popcount(x);
#else
    #error
#endif
}

inline int popcount(unsigned long x) {
#if defined(__GNUC__)
    return __builtin_popcountl(x);
#else
    #error
#endif
}

inline int popcount(unsigned long long x) {
#if defined(__GNUC__)
    return __builtin_popcountll(x);
#else
    #error
#endif
}
} // namespace jank::bit

#endif
