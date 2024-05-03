/*
Difficulty: Easy
Topics: Math, Bit Manipulation
Description:
Given an integer n, return true if it is a power of two.
Otherwise, return false.
An integer n is a power of two,
if there exists an integer x such that n == 2ˆx.
*/

#include <iostream>
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return n < 1 ? false : (n & (n - 1)) == 0 ? true
                                                  : false;
    }
};

int main()
{
    Solution solution;
    int n = 16;
    int result = solution.isPowerOfTwo(n);
    std::cout << "is power of two : " << result << std::endl;
    return 0;
}