#include <iostream>
#include <vector>

int longestSubstringNoRepeat(const std::string& str) {
    int cur_len = 0;
    int max_len = 0;
    std::vector<int> pos(26);
    for (int i = 0; i < 26; ++i) pos[i] = -1;

    for (int i = 0; i < str.length(); ++i) {
        int prev_idx = pos[str[i] - 'a'];
        if (prev_idx < 0 || i - prev_idx > cur_len) ++cur_len;
        else {
            if (cur_len > max_len) {
                max_len = cur_len;
            }
            cur_len = i - prev_idx;
        }
        pos[str[i] - 'a'] = i;
    }
    if (cur_len > max_len) {
        max_len = cur_len;
    }

    return max_len;
}

int main() {
    std::cout << longestSubstringNoRepeat("arabcacfr") << std::endl;
}
