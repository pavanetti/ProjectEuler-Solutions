#include <cmath>
#include <iostream>

int main() {
    constexpr int upper_bound = 10'000;

    int a0 = 1;
    int odd_periods_count = 0;
    int next_square = 4;
    int next_odd = 5;
    for (int n = 2; n <= upper_bound; ++n) {
        // Compute next square number as a sum of odd numbers:
        // nth square number is the sum of the first n odd numbers.
        // Square_{n+1} = Square_n + Odd_n
        // Odd_{n+1} = Odd_n + 2
        if (n == next_square) {
            a0 += 1;
            next_square += next_odd;
            next_odd += 2;
            continue;
        }

        int m = 0;
        int d = 1;
        int a = a0;
        int period = 0;

        while (a != a0 << 1) {
            period++;
            m = d * a - m;
            d = (n - m * m) / d;
            a = (a0 + m) / d;
        }
        if (period & 1) {
            odd_periods_count++;
        }
    }

    std::cout << odd_periods_count << std::endl;

}
