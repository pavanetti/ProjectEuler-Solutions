#include <iostream>

int method1() {
    long number = 600851475143L;

    int factor = 1;
    while (number > 1) {
        factor += 4;
        while (number % factor == 0)
            number = number / factor;

        if (number <= 1) break;
        factor += 2;

        while (number % factor == 0)
            number = number / factor;
    }
    return factor;
}

int main() {
    std::cout << method1();
}
