package main

import (
	"fmt"
)

func numbersOf1(n int32) int {
	count := 0
	for n != 0 {
		count++
		n &= n - 1
	}
	return count
}

func main() {
	fmt.Println(numbersOf1(-2))
}
