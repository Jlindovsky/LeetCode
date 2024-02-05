/*
Difficulty: Easy
Description:
You are given an integer array cost where cost[i] is the cost
of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
 */

#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int minCostClimbingStairs(std::vector<int> &cost)
    {
        int size = cost.size();
        std::vector<int> dp(size + 1, 0);

        for (int i = 2; i <= size; i++)
        {
            dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[size];
    }
};

int main()
{
    Solution solution;
    // Example 1
    std::vector<int> cost1 = {10, 15, 20};
    int result1 = solution.minCostClimbingStairs(cost1);
    std::cout << result1 << std::endl; // Output: 15
    // Example 2
    std::vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int result2 = solution.minCostClimbingStairs(cost2);
    std::cout << result2 << std::endl; // Output: 6

    return 0;
}