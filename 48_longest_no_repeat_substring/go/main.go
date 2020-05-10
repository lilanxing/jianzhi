package main

import (
	"fmt"
)

func LongestSubstringNoRepeat(s string) int {
	curLen, maxLen, pos := 0, 0, make([]int, 26)
	for i := 0; i < 26; i++ {
		pos[i] = -1
	}

	for i, ch := range s {
		if prevIdx := pos[ch - 'a']; prevIdx < 0 || i - prevIdx > curLen {
			curLen++
		} else {
			if curLen > maxLen {
				maxLen = curLen
			}
			curLen = i - prevIdx
		}
		pos[ch - 'a'] = i
	}
	if curLen > maxLen {
		maxLen = curLen
	}

	return maxLen
}

func main() {
	fmt.Println(LongestSubstringNoRepeat("araefbcacfr"))
}
