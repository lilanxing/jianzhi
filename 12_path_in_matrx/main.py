# -*- coding: utf-8 -*-


def has_path_core(matrix, rows, cols, row, col, s, params):
    if params['path_len'] == len(s):
        return True
    has_path = False
    if 0 <= row < rows and 0 <= col < cols and \
        matrix[row][col] == s[params['path_len']] and not \
        params['visited'][row * cols + col]:
        params['path_len'] += 1
        params['visited'][row * cols + col] = True
        has_path = has_path_core(matrix, rows, cols, row, col - 1, s, params) or \
            has_path_core(matrix, rows, cols, row - 1, col, s, params) or \
            has_path_core(matrix, rows, cols, row, col + 1, s, params) or \
            has_path_core(matrix, rows, cols, row + 1, col, s, params)
        if not has_path:
            params['path_len'] -= 1
            params['visited'][row * cols + col] = False
        else:
            print(params['path_len'], s[params['path_len'] - 1])
    return has_path


def has_path(matrix, s):
    if len(matrix) == 0 or len(matrix[0]) == 0 or s == '':
        return False
    rows, cols = len(matrix), len(matrix[0])
    params = {'path_len': 0, 'visited': [False] * (rows * cols)}
    for i in range(rows):
        for j in range(cols):
            if has_path_core(matrix, rows, cols, i, j, s, params):
                return True
    return False


if __name__ == '__main__':
    matrix = [
        ['a', 'b', 't', 'g'],
        ['c', 'f', 'c', 's'],
        ['j', 'd', 'e', 'h']
    ]
    print(has_path(matrix, 'bfcd'))
