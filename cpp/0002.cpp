#include <iostream>


// this recursive function can be tail-call optimized
int fibonacci(int n, int current = 0, int next = 1) {
    if (n < 1) return current;
    return fibonacci(n - 1, next, current + next);
}

// calls a recursive fibonacci function
int method1() {
    int sum = 0;
    int i = 0;

    int fib = fibonacci(i);
    while (fib < 4e6) {
        if (fib % 2 == 0)
            sum += fib;
        fib = fibonacci(++i);
    }
    return sum;
}

// iteratively calculates next fibonacci number without auxiliar variables
int method2() {
    int sum = 0;
    int current = 1, next = 1;
    while (current < 4e6) {
        if (current % 2 == 0)
            sum += current;

        next = current + next; // b+a
        current = next - current; // b+a-a
    }
    return sum;
}

int evenFibonacci(int n, int current = 2, int next = 8) {
    if (n < 1) return current;
    return evenFibonacci(n-1, next, 4 * next + current);
}

int method3() {
    int sum = 0;

    int i = 0, fib;
    do {
        fib = evenFibonacci(i++);
        sum += fib;
    } while (fib < 4e6);
    return sum - fib;
}

int method4() {
    int sum = 0;

    int current = 2, next = 8;
    while (current < 4e6) {
        sum += current;
        next = (next << 2) + current;
        current = (next - current) >> 2;
    }
    return sum;
}

int main() {
    std::cout << method1() << std::endl;
    std::cout << method2() << std::endl;
    std::cout << method3() << std::endl;
    std::cout << method4() << std::endl;
}
