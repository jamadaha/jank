
#ifndef JANK_FIXED_STACK
#define JANK_FIXED_STACK

#include <array>
#include <cassert>
#include <cstdint>
#include <memory>

namespace jank::container {
template <class T, std::size_t N> struct fixed_stack {
public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type &;
    using const_reference = const value_type &;

    // Member functions

    fixed_stack() : _i(0) {}
    fixed_stack(const fixed_stack &v) : _stack(v._stack), _i(v._i) {}
    ~fixed_stack() = default;

    fixed_stack operator=(const fixed_stack &other) {
        _stack = other._stack;
        _i = other._i;
    }

    // Capacity

    bool empty() const noexcept { return _i == 0; }
    size_type size() const noexcept { return _i; }
    size_type max_size() const noexcept { return N; }

    // Element access

    reference top() {
        assert(_i > 0);
        return _stack[_i - 1];
    }
    const_reference top() const {
        assert(_i > 0);
        return _stack[_i - 1];
    }

    // Modifiers

    void push(value_type &&value) {
        assert(_i < N);
        _stack[_i++] = value;
    }
    void pop() {
        assert(_i > 0);
        _i--;
    }

private:
    std::array<value_type, N> _stack;
    size_t _i;
};
} // namespace jank::container

#endif
