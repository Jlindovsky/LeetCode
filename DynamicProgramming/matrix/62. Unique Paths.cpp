/*
Difficulty: Medium
Topics: Math, Dynamic Programming, Combinatorics
Description:
There is a robot on an m x n grid.
The robot is initially located at the
top-left corner (i.e., grid[0][0]). The robot tries to move to the
bottom-right corner (i.e., grid[m - 1][n - 1]).
The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number
of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.
 */

#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // Function to calculate combination
        auto combination = [&](int n, int r) -> long long
        {
            long long result = 1;
            for (int i = 1; i <= r; ++i)
            {
                result *= n - (r - i);
                result /= i;
            }
            return result;
        };
        // up in combination number is steps needed to go to destination - m+n-2
        // down in combination number is number of down or right steps to reach down or right
        // order of stpes doesnt metter so we have combination
        long long result = combination(m + n - 2, std::min(m - 1, n - 1));

        return static_cast<int>(result);
    }
};

int main()
{
    int m, n = 0;
    std::cin >> m;
    std::cin >> n;
    // instance of the Solution class
    Solution solution;
    // sorted sequential digits within the specified range
    int result = solution.uniquePaths(m, n);

    std::cout << result;

    return 0;
}
