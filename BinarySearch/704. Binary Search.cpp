/*
Difficulty: Easy
Topics: Array, Binary Search
Description:
Given an array of integers nums which is sorted in ascending order,
and an integer target, write a function to search target in nums.
If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int binarySearch(const std::vector<int> &nums, int target, int left, int right)
    {
        if (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] > target)
            {
                return binarySearch(nums, target, left, mid - 1);
            }
            return binarySearch(nums, target, mid + 1, right);
        }
        // Target not found
        return -1;
    }

    int search(const std::vector<int> &nums, int target)
    {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};

int main()
{
    Solution solution;

    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    std::cout << "index of target: " << solution.search(nums, target) << std::endl;
    return 0;
}