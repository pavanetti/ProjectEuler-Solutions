/**
 * https://projecteuler.net/problem=100
 *
 * Let m be the number of blue discs and n be the number of total discs.
 * P(BB) = 1/2 => (m / n) * ((m - 1) / (n - 1)) = 1/2
 * => m * (m - 1) = n * (n - 1) / 2
 * => 2 * m^2 - 2 * m = n^2 - n
 * (x2) => 8 * m^2 - 8 * m = 4 * n^2 - 4 * n
 * (+ 1) => 8 * m^2 - 8 * m + 1 = 4 * n^2 - 4 * n + 1
 * => 8 * m^2 - 8 * m + 1 + (1 - 1) = (2 * n - 1)^2
 * => 2 * (4 * m^2 - 4 * m + 1) - 1 = (2 * n - 1)^2
 * => 2 * (2 * m - 1)^2 - 1 = (2 * n - 1)^2
 *
 * Let y = 2 * m - 1, x = 2 * n - 1, then we have:
 * 2 * y^2 - 1 = x^2 => x^2 - 2 * y^2 = -1
 *
 * Let's solve the Pell's equation. The minimal solution is (x_0, y_0) = (1, 1).
 * The general solution can be calculated from:
 *
 * x_{i+1} + y_{i+1} * sqrt(2) = (x_0 + y_0 * sqrt(2))^i = (1 + sqrt(2))^i
 *
 * for i odd. (even i results in y^2 - 2 * x^2 = 1).
 *
 * This yields the following recurrence relation:
 *
 * x_k = 3 * x_0 * x_k + 4 * y_0 * y_k = 3 * x_k + 4 * y_k
 * y_k = 2 * x_0 * y_k + 3 * y_0 * x_k = 2 * x_k + 3 * y_k
 *
 * [x_k, y_k] = [[3, 4], [2, 3]]^k * [1, 1]
 *
 * Any pair (x, y) gives m and n such that P(BB) = 1 / 2.
 *
 * Note that (x_0, y_0) = (1, 1) are both odd and (x_k, y_k) will keep the parity.
 * So we can find integer solutions for (m, n) from (x_k, y_k).
 *
 * We need to find the smallest k such that y > 10^12.
 * x_k, y_k grow each step roughly by the eigenvalue bigger than 1 of [[3, 4], [2, 3]],
 * which is 3 + 2 * sqrt(2).
 *
 * We may find a lower bound for k by solving:
 * (3 + 2 * sqrt(2))^k > 10^12
 * k * log(3 + 2 * sqrt(2)) > 12 * log(10)
 * k > 12 * log(10) / log(3 + 2 * sqrt(2))
 * k > 12 / log10(3 + 2 * sqrt(2)) ~= 15.67
 *
 * Our solution for (x, y) is: [[3, 4], [2, 3]]^16 * [1, 1]
 * And (m, n) = (y + 1) / 2, (x + 1) / 2
 */

#include <array>
#include <cstdint>
#include <iostream>
#include <cmath>

using matrix2x2 = std::array<std::int64_t, 4>;

matrix2x2 mul2x2(matrix2x2 a, matrix2x2 b) noexcept {
    matrix2x2 c;
    c[0] = a[0] * b[0] + a[1] * b[2];
    c[1] = a[0] * b[1] + a[1] * b[3];
    c[2] = a[2] * b[0] + a[3] * b[2];
    c[3] = a[2] * b[1] + a[3] * b[3];
    return c;
}

void print2x2(matrix2x2 a) {
    std::cout << a[0] << " " << a[1] << std::endl;
    std::cout << a[2] << " " << a[3] << std::endl;
}

matrix2x2 pow2x2(matrix2x2 a, std::uint8_t n) noexcept {
    matrix2x2 result = {1, 0, 0, 1};
    while (n > 0) {
        if (n & 1) {
            result = mul2x2(result, a);
        }
        if (n != 1) {
            a = mul2x2(a, a);
        }
        n >>= 1;
    }
    return result;
}

int main() {
    std::uint8_t k = std::ceil(12 / std::log10(3 +  2 *std::sqrt(2)));
    matrix2x2 g = {3, 4, 2, 3};
    matrix2x2 gk = pow2x2(g, k);

    std::int64_t x = gk[0] + gk[1];
    std::int64_t y = gk[2] + gk[3];
    std::int64_t m = (y + 1) >> 1;
    std::int64_t n = (x + 1) >> 1;

    std::cout << m << std::endl;
    return 0;
}
