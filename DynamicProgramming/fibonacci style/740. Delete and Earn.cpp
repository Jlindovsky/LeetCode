/*
Difficulty: Medium
Topics: Array,Hash Table, Dynamic Programming
Description:
You are given an integer array nums.
You want to maximize the number of points you
get by performing the following operation any number of times:
Pick any nums[i] and delete it to earn nums[i] points.
Afterwards, you must delete every element equal to nums[i] - 1
and every element equal to nums[i] + 1. Return the maximum number
of points you can earn by applying the above operation some number of times.
 */

#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int deleteAndEarn(std::vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        int max_num = *std::max_element(nums.begin(), nums.end());
        std::vector<int> points(max_num + 1, 0);

        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            points[num] += num;
        }

        int prev = 0, curr = 0;
        for (int i = 0; i < points.size(); ++i)
        {
            int temp = curr;
            curr = std::max(curr, prev + points[i]);
            prev = temp;
        }

        return curr;
    }
};

int main()
{
    Solution solution;
    // Example 1
    std::vector<int> nums1 = {3, 4, 2};
    int result1 = solution.deleteAndEarn(nums1);
    std::cout << result1 << std::endl; // Output: 6
    // Example 2
    std::vector<int> nums2 = {2, 2, 3, 3, 3, 4};
    int result2 = solution.deleteAndEarn(nums2);
    std::cout << result2 << std::endl; // Output: 9

    return 0;
}