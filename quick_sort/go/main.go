package main

import (
	"fmt"
)

func partition(nums *[]int, start, end int) int {
	if nums == nil || len(*nums) <= 0 || start <0 || end >= len(*nums) || start > end {
		return -1;
	}

	pivot := (*nums)[start]
	for start < end {
		for start < end && (*nums)[end] >= pivot {
			end--
		}
		(*nums)[start] = (*nums)[end]
		for start < end && (*nums)[start] <= pivot {
			start++
		}
		(*nums)[end] = (*nums)[start]
	}
	(*nums)[start] = pivot
	return start
}

func quicksortCore(nums *[]int, start, end int) {
	k := partition(nums, start, end)
	if k > start {
		quicksortCore(nums, start, k - 1)
	}
	if k < end {
		quicksortCore(nums, k + 1, end)
	}
}

func quicksort(nums *[]int) {
	quicksortCore(nums, 0, len(*nums) - 1)
}

func main() {
	nums := []int{4, 0, 9, -1, -2, -2, 8}
	quicksort(&nums)
	fmt.Println(nums)
}
