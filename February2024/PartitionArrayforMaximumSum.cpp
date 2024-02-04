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
