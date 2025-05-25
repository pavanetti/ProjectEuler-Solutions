#include <cmath>
#include <iostream>

int main() {
    constexpr int upper_bound = 10'000;

    int a0 = 1;
    int odd_periods = 0;
    for (int n = 2; n <= upper_bound; ++n) {
        if ((a0 + 1) * (a0 + 1) == n) {
            a0 += 1;
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
        if (period % 2 == 1) {
            odd_periods++;
        }
    }

    std::cout << odd_periods << std::endl;

}
