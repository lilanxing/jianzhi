# -*- coding: utf-8 -*-


def max_cut(n):
    if n < 2:
        return 0
    if n == 2:
        return 1
    if n == 3:
        return 2

    prods = [0] * (n + 1)
    prods[0], prods[1], prods[2], prods[3] = 0, 1, 2, 3

    for i in range(4, n + 1):
        _max = 0
        for j in range(1, i // 2 + 1):
            prod = prods[j] * prods[i - j]
            if prod > _max:
                _max = prod
        prods[i] = _max
    return prods[n]


if __name__ == '__main__':
    print(max_cut(8))
