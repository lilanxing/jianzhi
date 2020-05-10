#include <iostream>

bool match(const std::string& s, int s_pos, const std::string& pattern, int pattern_pos) {
    // std::cout << s_pos << ":" << pattern_pos << std::endl;
    // std::cout << (s[s_pos] == '\0') << "---" << std::endl;
    if (s.length() == s_pos && pattern.length() == pattern_pos) return true;
    if (s_pos < s.length() && pattern.length() == pattern_pos) return false;

    if (pattern_pos + 1 < pattern.length() && pattern[pattern_pos + 1] == '*') {
        if (s_pos < s.length() && (pattern[pattern_pos] == s[s_pos] || pattern[pattern_pos] == '.')) {
            return match(s, s_pos + 1, pattern, pattern_pos + 2) ||
                match(s, s_pos + 1, pattern, pattern_pos) ||
                match(s, s_pos, pattern, pattern_pos + 2);
        } else {
            return match(s, s_pos, pattern, pattern_pos + 2);
        }
    }
    if (s_pos < s.length() && (pattern[pattern_pos] == s[s_pos] || pattern[pattern_pos] == '.')) {
        return match(s, s_pos + 1, pattern, pattern_pos + 1);
    }

    return false;
}

bool match(const std::string& s, const std::string& pattern) {
    if (s.length() == 0 || pattern.length() == 0) return false;
    return match(s, 0, pattern, 0);
}

int main() {
    std::cout << match("aaa", "a.a") << std::endl;
    std::cout << match("aaa", "ab*ac*a") << std::endl;
    std::cout << match("aaa", "aa.a") << std::endl;
    std::cout << match("aaa", "ab*a") << std::endl;
}
