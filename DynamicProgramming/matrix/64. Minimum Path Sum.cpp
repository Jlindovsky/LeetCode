/*
Difficulty: Medium
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
#include <iostream>

using namespace std;

class Solution
{
public:
    // find shortest path using Dijkstra Algorithm
    int minPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size();    // Get the number of rows in grid
        int cols = grid[0].size(); // Get the number of columns in grid

        // Initialize dp with dimensions rows x cols and fill it with zeros
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        // loop thru grid
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[0][0] = grid[0][0];
                }
                else if (i == 0)
                {
                    dp[i][j] = grid[i][j] + dp[i][j - 1];
                }
                else if (j == 0)
                {
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                }
                else
                {
                    if (dp[i][j - 1] < dp[i - 1][j])
                    {
                        dp[i][j] = grid[i][j] + dp[i][j - 1];
                    }
                    else
                    {
                        dp[i][j] = grid[i][j] + dp[i - 1][j];
                    }
                }
            }
        }

        return dp[rows - 1][cols - 1];
    }
};
