package main

import (
	"fmt"
)

func Exchange(s string, i, j int) string {
	ss := []byte(s)
	ss[i], ss[j] = ss[j], ss[i]
	return string(ss)
}

func PermutationCore(str string, idx int) {
	if idx == len(str) {
		fmt.Println(str)
	} else {
		for i := idx; i < len(str); i++ {
			str = Exchange(str, i, idx)
			PermutationCore(str, idx + 1)
			str = Exchange(str, i, idx)
		}
	}
}

func Permutation(str string) {
	if str == "" {
		return
	}
	PermutationCore(str, 0)
}

func main() {
	Permutation("abc");
}
