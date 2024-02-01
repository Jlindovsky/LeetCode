#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> divideArray(std::vector<int> &nums, int k)
    {
        // Sort the input array
        std::sort(nums.begin(), nums.end());

        // Initialize result 2D array
        std::vector<std::vector<int>> result;

        // Initialize a temporary array to store subarrays
        std::vector<int> temp;

        // Inicialize a temporary Integer to store value to compare
        int tmp = nums[0];

        // Iterate through the sorted array
        for (int i = 0; i < nums.size(); ++i)
        {

            // If the temp array is empty or the difference between the current element
            // and the tmp element is less than or equal to k
            if (temp.empty() || nums[i] - tmp <= k)
            {
                // Add the current element to the temp array
                temp.push_back(nums[i]);

                // If the temp array reaches size 3, add it to the result,
                // clear the temp array and set tmp to next value in nums array
                if (temp.size() == 3)
                {
                    result.push_back(temp);
                    temp.clear();
                    tmp = nums[i + 1];
                }
            }
            else
            {
                // If the difference is greater than k, return an empty array
                return {};
            }
        }
        // If there are remaining elements in the temp array, add it to the result
        if (!temp.empty())
        {
            result.push_back(temp);
        }

        // Check if there are enough subarrays to cover all elements
        if (result.size() * 3 == nums.size())
        {
            return result;
        }
        else
        {
            return {};
        }
    }
};
