/*
Difficulty: Easy
Topics: Array, Binary Search
Description:
Four basic binary searches
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        int left = 0, right = int(nums.size()) - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }

    char nextGreatestLetter(std::vector<char> &letters, char target)
    {
        int left = 0;
        int right = letters.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return letters[left % letters.size()];
    }

    int binarySearch(const std::vector<int> &nums, int target, int left, int right)
    {
        if (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] > target)
            {
                return binarySearch(nums, target, left, mid - 1);
            }
            return binarySearch(nums, target, mid + 1, right);
        }
        // Target not found
        return -1;
    }
    int search(const std::vector<int> &nums, int target)
    {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
    int countNegatives(std::vector<std::vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        int row = rows - 1;
        int col = 0;
        // count from bottom left value
        while (row >= 0 && col < cols)
        {
            // if this col is < 0 all in row are
            if (grid[row][col] < 0)
            {
                count += (cols - col);
                row--;
            }
            else
            {
                col++;
            }
        }

        return count;
    }
};

int main()
{
    Solution solution;

    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    std::vector<char> letters = {'c', 'f', 'j'};
    std::vector<std::vector<int>> grid = {{-3, -2, -1, 1}, {-2, -1, 0, 2}, {-1, 0, 1, 3}};
    int target = 7;
    char target = 'd';
    // find index of target, if not there return -1
    std::cout << "index of target: " << solution.search(nums, target) << std::endl;
    // find index of target, if not there return right index to insert
    std::cout << "index of target: " << solution.searchInsert(nums, target) << std::endl;
    // return char greater than target, if greater than all retrun letters[0]
    std::cout << "next greater char: " << solution.nextGreatestLetter(letters, target) << std::endl;
    // count negative numbers in grid
    std::cout << "nember of negative numbers: " << solution.countNegatives(grid) << std::endl;
    return 0;
}