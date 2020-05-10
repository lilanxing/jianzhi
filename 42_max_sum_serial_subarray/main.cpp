#include <iostream>
#include <vector>

int FindGreatestSumOfSubArray(std::vector<int>& nums, int& max_sum) {
    if (nums.size() == 0) return 1;
    int cur_sum = 0;
    max_sum = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (cur_sum <= 0) cur_sum = nums[i];
        else cur_sum += nums[i];

        if (cur_sum > max_sum) max_sum = cur_sum;
    }
    return 0;
}

int main() {
    std::vector<int> nums = {1, -2, 3, 10, -4, 7, 2, -5};
    int max_sum = 0;
    int err = FindGreatestSumOfSubArray(nums, max_sum);
    if (err == 0) std::cout << max_sum << std::endl;
}
