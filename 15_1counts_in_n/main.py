# -*- coding: utf-8 -*-


def number_of_1(n):
    if n < 0:
        n &= 0xffffffff
    count = 0
    while n:
        count += 1
        n &= n - 1
    return count


if __name__ == '__main__':
    print(number_of_1(9))
