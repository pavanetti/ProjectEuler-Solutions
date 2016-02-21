#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(int number) {
    std::string normal = std::to_string(number);
    std::string reverse = std::to_string(number);
    std::reverse(reverse.begin(), reverse.end());
    return normal == reverse;
}

int answer4() {
    for (int diagonal = 0; diagonal < 1000+999; ++diagonal) {
        for (int i = (diagonal + 1) >> 1; i < 1000; ++i) {
            int j = diagonal - i;
            if (j < 0) break;
            if ((i % 11 != 0) && (j % 11 != 0)) break;

            int three_digits_product = (999 - i) * (999 - j);
            if (isPalindrome(three_digits_product))
                return three_digits_product;
        }
    }
    return 1;
}

int main() {
    std::cout << answer4() << std::endl;
}
