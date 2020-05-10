# -*-  coding: utf-8 -*-


def duplicate(nums):
    if len(nums) <= 0:
        return False, 0

    for i in range(len(nums)):
        if nums[i] < 0 or nums[i] >= len(nums):
            return False, 0
        while nums[i] != i:
            if nums[i] == nums[nums[i]]:
                return True, nums[i]
            nums[nums[0]], nums[0] = nums[0], nums[nums[0]]
    return False


if __name__ == '__main__':
    nums = [2, 3, 1, 0, 2, 5, 3]
    duplicated, dup_num = duplicate(nums)
    if not duplicated:
        print('no duplicated number')
    else:
        print('duplicated number is {0}'.format(dup_num))
