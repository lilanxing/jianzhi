#include <iostream>
#include <vector>
#include <set>

int Partition(std::vector<int>& nums, int start, int end) {
    if (nums.size() == 0 || start < 0 || end >= nums.size() || start > end) {
        return -1;
    }

    int pivot = nums[start];
    while (start < end) {
        while (start < end && nums[end] >= pivot) --end;
        nums[start] = nums[end];

        while (start < end && nums[start] <= pivot) ++start;
        nums[end] = nums[start];
    }
    nums[start] = pivot;
    return start;
}

int GetKthNum(std::vector<int>& nums, int k) {
    if (nums.size() == 0 || k <= 0) {
        return -1;
    }

    int start = 0;
    int end = nums.size() - 1;
    int idx = Partition(nums, start, end);
    while (idx >= 0 && idx != k - 1) {
        if (idx > k - 1) end = idx - 1;
        else start = idx + 1;
        idx = Partition(nums, start, end);
    }

    return nums[k - 1];
}

int GetKthNumHeap(std::vector<int>& nums, int k, int& k_num) {
    if (k < 1 || nums.size() < k) return 1;
    
    std::multiset<int, std::greater<int>> heap;
    std::multiset<int, std::greater<int>>::iterator iter_heap;

    for (int i = 0; i < nums.size(); ++i) {
        if (heap.size() < k) heap.insert(nums[i]);
        else {
            iter_heap = heap.begin();
            if (nums[i] < *(iter_heap)) {
                heap.erase(iter_heap);
                heap.insert(nums[i]);
            }
        }
    }

    k_num = *(heap.begin());
    return 0;
}

int main() {
    std::vector<int> nums = {11, 21, 31, 41, 51};
    std::cout << GetKthNum(nums, 2) << std::endl;

    nums = {11, 21, 31, 41, 51};
    int k_num;
    int err = GetKthNumHeap(nums, 2, k_num);
    if (err == 0) std::cout << "heap kth min: " << k_num << std::endl;
}
