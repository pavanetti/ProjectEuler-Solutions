#include <iostream>

inline int isDivisible(int n, int d) { return n % d == 0; }

int method1() {
    int sum = 0;
    for (int number = 1; number < 1E3; number++) {
        if (isDivisible(number, 3) || isDivisible(number, 5)) {
            sum += number;
        }
    }
    return sum;
}


inline int sumTo(int n) { return n * (n + 1) / 2; }
int method2() {
    const int UPPER_LIMIT = 1E3 - 1;
    return 3 * sumTo(UPPER_LIMIT / 3)
        +  5 * sumTo(UPPER_LIMIT / 5)
        - 15 * sumTo(UPPER_LIMIT / 15);
}

int main() {
    std::cout << method1() << std::endl;
    std::cout << method2() << std::endl;
}
