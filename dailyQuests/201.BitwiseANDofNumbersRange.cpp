/*
Difficulty: Medium
Topics: Bit Manipulation
Description:
Given two integers left and right that represent the range [left, right],
return the bitwise AND of all numbers in this range, inclusive.
*/

#include <iostream>
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        std::bitset<sizeof(int) * 8> leftB(left);
        std::bitset<sizeof(int) * 8> rightB(right);
        std::bitset<sizeof(int) * 8> result(0);
        for (int i = leftB.size() - 1; i >= 0; i--)
        {
            if (leftB[i] == rightB[i])
            {
                if (leftB[i])
                {
                    result.set(i);
                }
            }
            else
            {
                break;
            }
        }
        return (int)result.to_ulong();
    }
};

int main()
{
    Solution solution;
    int left = 5;
    int right = 7;
    std::cout << "Range Bitwise AND: " << solution.rangeBitwiseAnd(left, right) << std::endl;
    return 0;
}