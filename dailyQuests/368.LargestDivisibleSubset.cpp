/*
Difficulty: Medium
Topics: Array, Math, Dynamic Programming, Sorting
Description:
Given a set of distinct positive integers nums,
return the largest subset answer such that every
pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.
*/

#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    std::vector<int> largestDivisibleSubset(std::vector<int> &nums)
    {
        if (nums.empty())
            return {};
        // sort array
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> dp(nums.size(), std::vector<int>());

        // double loop to find in which vector should new number from nums be added
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                // add if it is divisible and add to largest vector
                if (nums[i] % nums[j] == 0 && dp[i].size() < dp[j].size() + 1)
                    dp[i] = dp[j];
            }
            dp[i].push_back(nums[i]);
        }

        auto max_index = std::max_element(
            dp.begin(), dp.end(),
            [](const auto &a, const auto &b)
            { return a.size() < b.size(); });

        return *max_index;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 4, 6, 12};
    std::vector<int> result = solution.largestDivisibleSubset(nums);
    std::cout << "Largest divisible subset: ";
    for (int num : result)
        std::cout << num << " ";
    std::cout << std::endl;
    return 0;
}