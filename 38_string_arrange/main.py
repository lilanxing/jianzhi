# -*- coding: utf-8 -*-


def exchange(s, i, j):
    a = [e for e in s]
    a[i], a[j] = a[j], a[i]
    return ''.join(a)


def permutation_core(s, idx):
    if idx == len(s):
        print(s)
    else:
        for i in range(idx, len(s)):
            s = exchange(s, i, idx)
            permutation_core(s, idx + 1)
            s = exchange(s, i, idx)


def permutation(s):
    if len(s) == 0:
        return
    permutation_core(s, 0)
            
            
if __name__ == '__main__':
    permutation("abc")
