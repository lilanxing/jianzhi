package main

import (
	"fmt"
)

func hasPathCore(matrix [][]byte, rows, cols, row, col int,
	s string, pathLen *int, visited *[]bool) bool {
	if *pathLen == len(s) {
		return true
	}
	hasPath := false
	if row >= 0 && row < rows && col >= 0 && col < cols &&
		matrix[row][col] == s[*pathLen] && !(*visited)[row * cols + col] {
		*pathLen++
		(*visited)[row * cols + col] = true
		hasPath = hasPathCore(matrix, rows, cols, row, col - 1, s, pathLen, visited) ||
			hasPathCore(matrix, rows, cols, row - 1, col, s, pathLen, visited) ||
			hasPathCore(matrix, rows, cols, row, col + 1, s, pathLen, visited) ||
			hasPathCore(matrix, rows, cols, row + 1, col, s, pathLen, visited)
		if !hasPath {
			*pathLen--
			(*visited)[row * cols + col] = false
		}
	}
	return hasPath
}

func HasPath(matrix [][]byte, s string) bool {
	if matrix == nil || len(matrix) == 0 || len(matrix[0]) == 0 || s == "" {
		return false
	}
	rows, cols := len(matrix), len(matrix[0])
	pathLen, visited := 0, make([]bool, rows * cols)
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if hasPathCore(matrix, rows, cols, i, j, s, &pathLen, &visited) {
				return true
			}
		}
	}
	return false
}

func main() {
	matrix := [][]byte{
		{'a', 'b', 't', 'g'},
		{'c', 'f', 'c', 's'},
		{'j', 'd', 'e', 'h'},
	}
	s := "bfdehsc"
	fmt.Println(HasPath(matrix, s))
}
