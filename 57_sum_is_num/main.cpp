#include <iostream>
#include <vector>

bool TwoSum(const std::vector<int>& nums, const int sum, int& num1, int& num2) {
    if (nums.size() < 2) return false;

    int i = 0;
    int j = nums.size() - 1;
    while (i < j) {
        long long cur_sum = nums[i] + nums[j];
        if (cur_sum == sum) {
            num1 = nums[1];
            num2 = nums[2];
            return true;
        } else if (cur_sum > sum) --j;
        else ++i;
    }
    return false;
}
