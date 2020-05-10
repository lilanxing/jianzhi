package main

import (
	"fmt"
)

func maxCut(n int) int {
	if n < 2 {
		return 0
	}
	if n == 2 {
		return 1
	}
	if n == 3 {
		return 2
	}

	prods := make([]int, n + 1)
	prods[0], prods[1], prods[2], prods[3] = 0, 1, 2, 3

	for i := 4; i <= n; i++ {
		max := 0
		for j := 1; j <= i / 2; j++ {
			prod := prods[j] * prods[i - j]
			if prod > max {
				max = prod
			}
		}
		prods[i] = max
	}
	return prods[n]
}

func main() {
	fmt.Println(maxCut(8))
}
