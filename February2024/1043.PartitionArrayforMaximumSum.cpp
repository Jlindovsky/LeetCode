/*
Difficulty: Medium
Description:
Given an integer array arr, partition the array into (contiguous)
subarrays of length at most k. After partitioning, each subarray
has their values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning.
Test cases are generated so that the answer fits in a 32-bit integer.*/

#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int maxSumAfterPartitioning(std::vector<int> &arr, int k)
    {
        int n = arr.size();
        std::vector<int> helpArr(n + 1, 0);

        // loop thru array
        for (int i = 1; i <= n; ++i)
        {
            int maxVal = 0;
            // loop thru all possible partitions
            for (int j = 1; j <= k && i - j >= 0; ++j)
            {
                // find max val in different sizes of partition
                maxVal = std::max(maxVal, arr[i - j]);
                helpArr[i] = std::max(helpArr[i], helpArr[i - j] + maxVal * j);
            }
        }

        return helpArr[n];
    }
};

int main()
{
    // sample array
    std::vector<int> arr = {1, 15, 7, 9, 2, 5};
    int k = 3;

    // the original array
    std::cout << "Original Array:" << std::endl;
    for (const auto &num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // instance of the Solution class
    Solution solution;

    // the largest sum after partitioning
    int result = solution.maxSumAfterPartitioning(arr, k);

    std::cout << "\nLargest Sum After Partitioning:" << std::endl;
    std::cout << result << std::endl;

    return 0;
}