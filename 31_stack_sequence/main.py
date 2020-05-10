# -*- coding: utf-8 -*-


def is_pop_order(push, pop):
    possible = False
    if len(push) > 0 and len(pop) > 0 and len(push) == len(pop):
        s, push_idx, pop_idx = [], 0, 0

        while pop_idx < len(pop):
            while len(s) == 0 or s[-1] != pop[pop_idx]:
                if push_idx == len(push):
                    break
                s.append(push[push_idx])
                push_idx += 1
            if s[-1] != pop[pop_idx]:
                break
            s.pop()
            pop_idx += 1

        if len(s) == 0 and pop_idx == len(pop):
            possible = True
    return possible


if __name__ == '__main__':
    print(is_pop_order([1, 2, 3, 4, 5], [5, 4, 3, 2, 1]))
    print(is_pop_order([1, 2, 3, 4, 5], [5, 3, 4, 1, 2]))
