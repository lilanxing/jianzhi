package main

import (
	"fmt"
)

func Duplicate(nums []int) (bool, int) {
	size := len(nums)
	if size <= 0 {
		return false, 0
	}

	for i := range nums {
		if nums[i] < 0 || nums[i] >= size {
			return false, 0
		}
		for nums[i] != i {
			if nums[i] == nums[nums[i]] {
				return true, nums[i]
			}
			nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
		}
	}

	return false, 0
}

func main() {
	nums := []int{2, 3, 1, 0, 2, 5, 3}
	duplicated, dupNum := Duplicate(nums)
	if !duplicated {
		fmt.Println("no duplicated number")
	} else {
		fmt.Printf("duplicated number is %d\n", dupNum)
	}
}
