#include <iostream>
#include <vector>

int maxProdCuting(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;

    std::vector<int> prods(n + 1);
    prods[0] = 0;
    prods[1] = 1;
    prods[2] = 2;
    prods[3] = 3;

    for (int i = 4; i <= n; ++i) {
        int max = 0;
        for (int j = 1; j <= i / 2; ++j) {
            int prod = prods[j] * prods[i - j];
            if (prod > max) max = prod;
        }
        prods[i] = max;
    }
    return prods[n];
}

int main() {
    std::cout << maxProdCuting(8) << std::endl;
}
