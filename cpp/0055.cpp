#include <array>
#include <cstdint>
#include <iostream>

using digits_t = std::array<std::uint8_t, 32>;

inline void sum_with_reverse(const digits_t &digits, digits_t &output, std::size_t size) noexcept {
    output.fill(0);
    std::uint8_t carry = 0;
    for (std::size_t i = 0; i < size; i++) {
        std::uint8_t sum = digits[i] + digits[size - (i + 1)] + carry;
        output[i] = sum % 10;
        carry = sum > 9 ? 1 : 0;
    }
    if (carry) {
        output[size] = 1;
    }
}

inline bool is_palindrome(const digits_t &digits, std::size_t size) noexcept {
    for (std::size_t i = 0; i < size / 2; i++) {
        if (digits[i] != digits[size - (i + 1)]) {
            return false;
        }
    }
    return true;
}

inline bool is_lychrel(digits_t &current, digits_t &scratch, std::size_t size) noexcept {
    static constexpr std::size_t MAX_ITERATIONS = 50;
    for (std::size_t i = 0; i < MAX_ITERATIONS; i++) {
        sum_with_reverse(current, scratch, size);
        std::swap(current, scratch);
        if (current[size] != 0) { size += 1; }
        if (is_palindrome(current, size)) {
            return false;
        }
    }
    return true;
}

inline void increment_digits(digits_t &digits, std::size_t &size) noexcept {
    for (std::size_t j = 0; j < size; j++) {
        if (++digits[j] < 10) { break; }
        digits[j] = 0;
        if (j + 1 == size) { size += 1; }
    }
}

std::int32_t count_lychrel(std::size_t upper_bound) {
    digits_t digits{};
    digits_t mutable_digits{};
    digits_t added_output;
    std::int32_t count = 0;

    std::int32_t number = 0;
    std::size_t size = 1;
    for (std::size_t i = 0; i < upper_bound; i++) {
        number += 1;
        increment_digits(digits, size);
        mutable_digits = digits;
        if (is_lychrel(mutable_digits, added_output, size)) {
            count += 1;
        }
    }
    return count;
}

int main() {
    std::cout << "Count: " << count_lychrel(10'000) << std::endl;
    return 0;
}
