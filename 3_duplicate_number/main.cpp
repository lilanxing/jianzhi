#include <iostream>
#include <vector>

bool duplicate(std::vector<int>& nums, int& duplication) {
    const int len = nums.size();
    if (len <= 0) return false;

    for (int i = 0; i < len; ++i) {
        if (nums[i] < 0 || nums[i] >= len) return false;
        while (nums[i] != i) {
            if (nums[i] == nums[nums[i]]) {
                duplication = nums[i];
                return true;
            }
            int tmp = nums[i];
            nums[i] = nums[tmp];
            nums[tmp] = tmp;
        }
    }

    return false;
}

int main() {
    std::vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    int dup;
    bool duplicated = duplicate(nums, dup);
    if (!duplicated) std::cout << "no duplicate number" << std::endl;
    else std::cout << "duplicate number is " << dup << std::endl;
}
