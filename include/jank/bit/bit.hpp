#ifndef JANK_BIT
#define JANK_BIT

namespace jank::bit {
inline int LSB(unsigned int x) {
#if defined(__GNUC__)
    return __builtin_ctz(x);
#endif
}

inline int LSB(unsigned long x) {
#if defined(__GNUC__)
    return __builtin_ctzl(x);
#endif
}

inline int LSB(unsigned long long x) {
#if defined(__GNUC__)
    return __builtin_ctzll(x);
#endif
}

inline int MSB(unsigned int x) {
#if defined(__GNUC__)
    return __builtin_clz(x);
#endif
}

inline int MSB(unsigned long x) {
#if defined(__GNUC__)
    return __builtin_clzl(x);
#endif
}

inline int MSB(unsigned long long x) {
#if defined(__GNUC__)
    return __builtin_clzll(x);
#endif
}

inline int popcount(unsigned int x) {
#if defined(__GNUC__)
    return __builtin_popcount(x);
#endif
}

inline int popcount(unsigned long x) {
#if defined(__GNUC__)
    return __builtin_popcountl(x);
#endif
}

inline int popcount(unsigned long long x) {
#if defined(__GNUC__)
    return __builtin_popcountll(x);
#endif
}

} // namespace jank::bit

#endif
