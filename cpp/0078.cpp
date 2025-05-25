#include <iostream>
#include <vector>

int main() {
    constexpr int MOD = 1'000'000;
    std::vector<std::int32_t> p;
    p.reserve(60'000);
    p.push_back(1);

    for (int n = 1; ; ++n) {
        std::int64_t acc = 0;

        // sum over k = 1, 2, 3, ... until generalized pentagonal numbers exceed n
        for (int k = 1; ; ++k) {
            // generalized pentagonal numbers: g(k) = k(3k-1)/2, g(-k) = k(3k+1)/2
            std::int32_t g1 = k * (3 * k - 1) >> 1;
            if (g1 > n) break;

            int sign = (k & 1 ? +1 : -1);
            acc += sign * p[n - g1];

            std::int32_t g2 = k * (3 * k + 1) >> 1;
            if (g2 > n) continue;

            acc += sign * p[n - g2];
        }

        std::int32_t pn = static_cast<std::int32_t>((acc % MOD + MOD) % MOD);
        p.push_back(pn);

        if (pn == 0) {
            // Found the answer
            std::cout << n << std::endl;
            break;
        }
    }

    return 0;
}
