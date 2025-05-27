/*
To a natural number y to have n digits, we need to have 10^{n-1} <= y < 10^n.
If y is an nth power, exists a natural number x such that y = x^n.

So, 10^{n-1} <= x^n < 10^n.
From x^n < 10^n, we have x < 10. We just need to look for 0 < x <= 9.
From 10^{n-1} <= x^n, we have log_{10}(10^{n-1}) <= n log_{10}(x).
So, n - 1 <= n * log_{10}(x)
 => n - n * log_{10}(x) <= 1
 => n * (1 - log_{10}(x)) <= 1
 => n <= 1/(1 - log_{10}(x)).

So for each x such that 0 < x <= 9
any natural number n such that n <= 1/(1 - log_{10}(x)) is a solution.

*/

#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char* argv[]) {
    int sum = 0;
    for (int x = 1; x <= 9; x++) {
        int n = std::floor(1.0 / (1 - log10(x)));
        sum += n;
    }
    std::cout << sum << std::endl;
    return 0;
}
