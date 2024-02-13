/*
Difficulty: medium
Topics: Array, Dynamic Programming
Description:
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that
adjacent houses have security systems connected and
it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.
*/

#include <vector>
#include <algorithm>
#include <iostream>

#include <iostream>
#include <vector>

int rob(std::vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return nums[0];
    }
    else if (n == 2)
    {
        return std::max(nums[0], nums[1]);
    }

    // Create an array to store the maximum amount of money robbed up to each house
    std::vector<int> dp(n, 0);

    // Base cases
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    // Dynamic programming to calculate the maximum amount of money robbed
    for (int i = 2; i < n; ++i)
    {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n - 1];
}

int main()
{
    std::vector<int> nums1 = {1, 2, 3, 1};
    std::cout << "Example 1: " << rob(nums1) << std::endl;

    std::vector<int> nums2 = {2, 7, 9, 3, 1};
    std::cout << "Example 2: " << rob(nums2) << std::endl;

    return 0;
}
