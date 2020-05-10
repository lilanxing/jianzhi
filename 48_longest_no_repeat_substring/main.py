# -*- coding: utf-8 -*-


def longest_substring_no_repeat(s):
    cur_len, max_len, pos = 0, 0, [-1] * 26

    for i in range(len(s)):
        prev_idx = pos[ord(s[i]) - 97]
        if prev_idx < 0 or i - prev_idx > cur_len:
            cur_len += 1
        else:
            if cur_len > max_len:
                max_len = cur_len
            cur_len = i - prev_idx
        pos[ord(s[i]) - 97] = i
    if cur_len > max_len:
        max_len = cur_len
    return max_len


if __name__ == '__main__':
    print(longest_substring_no_repeat('arabcacfr'))
