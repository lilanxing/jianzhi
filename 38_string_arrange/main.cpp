#include <iostream>

void PermutationCore(std::string& str, int idx) {
    if (idx == str.length()) std::cout << str << std::endl;
    else {
        for (int i = idx; i < str.length(); ++i) {
            std::swap(str[i], str[idx]);
            PermutationCore(str, idx + 1);
            std::swap(str[i], str[idx]);
        }
    }
}

void Permutation(std::string& str) {
    if (str.length() == 0) return;
    PermutationCore(str, 0);
}

int main() {
    std::string str = "abc";
    Permutation(str);
}
