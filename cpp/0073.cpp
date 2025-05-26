#include <cmath>
#include <iostream>
#include <mmintrin.h>

inline bool is_even(int x) {
    return !(x & 1);
}

inline int reduce_to_odd(int x) {
    while (is_even(x)) {
        x >>= 1;
    }
    return x;
}

int binary_gcd(int a, int b) {
    int p = 0;
    while (is_even(a | b)) {
        a >>= 1;
        b >>= 1;
        p += 1;
    }
    a = reduce_to_odd(a);
    b = reduce_to_odd(b);

    while (a != b) {
        if (a > b) {
            std::swap(a, b);
        }
        b = reduce_to_odd(b - a);
    }

    return a << p;
}

int main() {
    int D = 12'000;
    int count = 0;
    for (int d = 4; d <= D; d++) {
        for (int n = std::ceil(d / 3.0); 2 * n < d; n++) {
            if (binary_gcd(n, d) <= 1) {
                count++;
            }
        }
    }
    std::cout << count << std::endl;
}
