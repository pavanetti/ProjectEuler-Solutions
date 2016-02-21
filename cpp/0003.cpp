#include <iostream>


#define increment_factor(n) \
    factor += (n); \
    if (factor * factor > backup_number) { \
        factor -= (n); \
        break; \
    }

int answer3() {
    long number = 600851475143L;
    long backup_number = number;

    int factor = 1;
    while (number > 1) {
        increment_factor(4);

        while (number % factor == 0)
            number = number / factor;

        if (number <= 1) break;
        increment_factor(2);


        while (number % factor == 0)
            number = number / factor;
    }
    return factor;
}

int main() {
    std::cout << anser3() << std::endl;
}
