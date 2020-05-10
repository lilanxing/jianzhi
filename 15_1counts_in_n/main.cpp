#include <iostream>

int NumberOf1(int n) {
    int count = 0;
    while (n) {
        n &= n - 1;
        ++count;
    }
    return count;
}

int main() {
    std::cout << NumberOf1(-2) << std::endl;
}
