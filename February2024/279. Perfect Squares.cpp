/*
Difficulty: Medium
Topics: Math, Dynamic Programming, Breadth-First Search
Description:
Given an integer n, return the least number of
perfect square numbers that sum to n.
A perfect square is an integer that is the square of an integer;
in other words, it is the product of some integer with itself.
For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
*/

#include <iostream>
#include <vector>
#include <cmath>

class Solution
{
public:
    int numSquares(int n)
    {
        std::vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        // loop through dp vector
        for (int i = 1; i <= n; ++i)
        {
            // loop through squared values
            for (int j = 1; j * j <= i; ++j)
            {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution solution;
    int n = 5;
    int result = solution.numSquares(n);
    std::cout << "least square numbers: " << result << std::endl;
    return 0;
}