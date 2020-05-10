# -*- coding: utf-8 -*-


def match_core(s, s_pos, p, p_pos):
    if p_pos == len(p) and s_pos == len(s):
        return True
    if p_pos == len(p) and s_pos < len(s):
        return False

    if p_pos + 1 < len(p) and p[p_pos + 1] == '*':
        if s_pos < len(s) and (p[p_pos] == s[s_pos] or p[p_pos] == '.'):
            return match_core(s, s_pos + 1, p, p_pos + 2) or \
                match_core(s, s_pos + 1, p, p_pos) or \
                match_core(s, s_pos, p, p_pos + 2)
        else:
            return match_core(s, s_pos, p, p_pos + 2)

    if s_pos < len(s) and (p[p_pos] == s[s_pos] or p[p_pos] == '.'):
        return match_core(s, s_pos + 1, p, p_pos + 1)

    return False


def match(s, p):
    if s == '' or p == '':
        return False
    return match_core(s, 0, p, 0)


if __name__ == '__main__':
    print(match('aaa', 'a.a'))
    print(match('aaa', 'ab*ac*a'))
    print(match('aaa', 'aa.a'))
    print(match('aaa', 'ab*a'))
