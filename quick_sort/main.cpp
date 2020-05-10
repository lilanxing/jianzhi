#include <iostream>
#include <vector>

int Partition(std::vector<int>& nums, int start, int end) {
    const int len = nums.size();
    if (len <= 0 || start < 0 || end >= len || start > end) {
        return -1;
    }

    std::swap(nums[start], nums[end]);
    int k = start - 1;
    for (int i = start; i < end; ++i) {
        if (nums[i] < nums[end]) {
            ++k;
            if (k != i) {
                std::swap(nums[i], nums[k]);
            }
        }
    }
    ++k;
    std::swap(nums[k], nums[end]);
    return k;
}

void QuickSortCore(std::vector<int>& nums, int start, int end) {
    if (start == end) return;
    int k = Partition(nums, start, end);
    if (k > start) QuickSortCore(nums, start, k - 1);
    if (k < end) QuickSortCore(nums, k + 1, end);
}

void QuickSort(std::vector<int>& nums) {
    QuickSortCore(nums, 0, nums.size() - 1);
}

int main() {
    std::vector<int> nums = {5, 7, 9, 1, 0, -2};
    QuickSort(nums);
    for (int i = 0; i < nums.size(); ++i) std::cout << nums[i] << " ";
    std::cout << std::endl;
}
