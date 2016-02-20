#include <iostream>

int method1() {
    int sum = 0;
    for (int number = 1; number < 1E3; number++) {
        if (number % 3 == 0 || number % 5 == 0) {
            sum += number;
        }
    }
    return sum;
}

int main() {
    std::cout << method1() << std::endl;
}
