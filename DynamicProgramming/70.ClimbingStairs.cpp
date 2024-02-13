/*
Difficulty: Easy
Topics: Math, Dynamic Programming, Memoization
Description:
You are climbing a staircase.
It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps.
In how many distinct ways can you climb to the top?
*/

#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }
        // vector size of n+1 filled with zeros
        std::vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i)
        {
            // to dp[i] we can come from previous step
            // or from one from previous, thats why we need to add them
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main()
{
    int num = 0;
    std::cin >> num;
    // instance of the Solution class
    Solution solution;
    // sorted sequential digits within the specified range
    int result = solution.climbStairs(num);

    std::cout << result;

    return 0;
}