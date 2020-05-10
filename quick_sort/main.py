# -*- coding: utf-8 -*-


def partition(nums, start, end):
    if len(nums) <= 0 or start < 0 or end >= len(nums) or start > end:
        return
    pivot = nums[start]
    while start < end:
        while start < end and nums[end] >= pivot:
            end -= 1
        nums[start] = nums[end]
        while start < end and nums[start] <= pivot:
            start += 1
        nums[end] = nums[start]
    nums[start] = pivot
    return start


def quick_sort_core(nums, start, end):
    if len(nums) <= 0 or start > end:
        return
    k = partition(nums, start, end)
    if k > start:
        quick_sort_core(nums, start, k - 1)
    if k < end:
        quick_sort_core(nums, k + 1, end)


def quick_sort(nums):
    if len(nums) <= 0:
        return
    quick_sort_core(nums, 0, len(nums) - 1)


if __name__ == '__main__':
    nums = [4, 9, 0, 0, -1, -2, 4]
    quick_sort(nums)
    print(nums)
