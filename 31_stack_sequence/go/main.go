package main

import (
	"fmt"
)

func IsPopOrder(push, pop []int) bool {
	possible := false
	if len(push) > 0 && len(pop) > 0 && len(push) == len(pop) {
		s, pushIdx, popIdx := make([]int, 0, len(push)), 0, 0
		for popIdx < len(pop) {
			for len(s) == 0 || s[len(s) - 1] != pop[popIdx] {
				if pushIdx == len(push) {
					break
				}
				s = append(s, push[pushIdx])
				pushIdx++
			}
			if s[len(s) - 1] != pop[popIdx] {
				break
			}
			s = s[:len(s) - 1]
			popIdx++
		}
		if len(s) == 0 && popIdx == len(pop) {
			possible = true
		}
	}
	return possible
}

func main() {
	fmt.Println(IsPopOrder([]int{1, 2, 3, 4, 5}, []int{5, 4, 3, 2, 1}))
	fmt.Println(IsPopOrder([]int{1, 2, 3, 4, 5}, []int{5, 3, 4, 1, 2}))
}
