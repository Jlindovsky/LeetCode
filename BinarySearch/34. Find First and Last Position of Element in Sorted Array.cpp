/*
Difficulty: Medium
Topics: Array, Binary Search
Description:
Given an array of integers nums sorted in non-decreasing order,
find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
*/
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        vector<int> result = {-1, -1};

        if (nums.size() == 1 && nums[0] == target)
        {
            result = {0, 0};
            return result;
        }

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                int i = mid;
                while (i >= 0 && nums[i] == nums[mid])
                {
                    result[0] = i;
                    i--;
                }
                i = mid;
                while (i < nums.size() && nums[i] == nums[mid])
                {
                    result[1] = i;
                    i++;
                }
                break;
            }
            else if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;

    // Input grid
    vector<int> nums = {3, 1, 1};
    int target = 1;

    // Call the cherryPickup function and print the result
    vector<int> result = solution.searchRange(nums, target);
    cout << "starting and ending position of target value: " << result[0] << "and" << result[1] << endl;

    return 0;
}