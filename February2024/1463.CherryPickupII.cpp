/*
Difficulty: Hard
Topics: Array, Dynamic Programming, Matrix
Description:
You are given a rows x cols matrix grid representing
a field of cherries where grid[i][j] represents the
number of cherries that you can collect from the (i, j) cell.
You have two robots that can collect cherries for you:
Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:
From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
*/

#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int columnMovements[3] = {
        0, -1, 1};                    // Array to represent changes in column indices
    int memoizationTable[71][71][71]; // Memoization table

    // Depth-first search function to find the maximum number of cherries picked
    int dfs(vector<vector<int>> &grid, int row, int picker1Col, int picker2Col,
            int rows, int cols)
    {
        // Base cases
        if (row == rows)
            return 0; // Reached end of grid
        if (picker1Col < 0 || picker2Col < 0 || picker1Col >= cols ||
            picker2Col >= cols)
            return INT_MIN; // Out of bounds
        if (memoizationTable[row][picker1Col][picker2Col] != -1)
            return memoizationTable[row][picker1Col]
                                   [picker2Col]; // Already calculated

        // Initialization
        int maxCherries = 0;

        // Try all possible movements for both pickers
        for (int move1 = 0; move1 < 3; move1++)
        {
            for (int move2 = 0; move2 < 3; move2++)
            {
                // Explore next position
                maxCherries =
                    max(maxCherries,
                        dfs(grid, row + 1, picker1Col + columnMovements[move1],
                            picker2Col + columnMovements[move2], rows, cols));
            }
        }

        // Add cherries picked at current position(s) to the answer
        maxCherries += (picker1Col == picker2Col)
                           ? grid[row][picker1Col]
                           : grid[row][picker1Col] + grid[row][picker2Col];

        // Memoize and return the result
        return memoizationTable[row][picker1Col][picker2Col] = maxCherries;
    }

    // Main function to initiate the cherry-picking process
    int cherryPickup(vector<vector<int>> &grid)
    {
        int rows = grid.size(); // Total number of rows
        if (!rows)
            return 0;              // Empty grid
        int cols = grid[0].size(); // Total number of columns

        // Initialize memoization table with -1
        memset(memoizationTable, -1, sizeof memoizationTable);

        // Start DFS from the first row and columns 0 and n-1
        return dfs(grid, 0, 0, cols - 1, rows, cols);
    }
};

int main()
{
    Solution solution;

    // Input grid
    vector<vector<int>> grid = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1}};

    // Call the cherryPickup function and print the result
    int maxCherries = solution.cherryPickup(grid);
    cout << "Maximum cherries that can be picked: " << maxCherries << endl;

    return 0;
}
