/*
Difficulty: Medium
Topics: Enumeration
Description:
An integer has sequential digits if and only if each digit
in the number is one more than the previous digit.
Return a sorted list of all the integers
in the range [low, high] inclusive that have sequential digits.
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> sequentialDigits(int low, int high)
    {
        // sorted array
        std::vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::vector<int> result{};
        int temp = 0;
        // loop increasing number of digits in sequential number
        for (int i = 1; i < 9; i++)
        {
            // loop thru array with specified number of digits
            for (int j = 0; j < (9 - i); j++)
            {
                int l = j;
                int k = i;
                // creating  number from digits
                while (k >= 0)
                {
                    temp = temp * 10 + arr[l];
                    k--;
                    l++;
                }
                // controling if number is in asked interval
                if ((temp >= low) && (temp <= high))
                {
                    result.push_back(temp);
                }
                temp = 0;
            }
        }
        return result;
    }
};

int main()
{
    int low = 100;
    int high = 3000;

    // instance of the Solution class
    Solution solution;

    // sorted sequential digits within the specified range
    std::vector<int> result = solution.sequentialDigits(low, high);

    std::cout << "Sorted Sequential Digits in the Range [" << low << ", " << high << "]:" << std::endl;
    for (const auto &num : result)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
