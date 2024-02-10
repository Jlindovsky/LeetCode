/*
Difficulty: Medium
Topics: String, Dynamic Programming
Description:
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.
 */
#include <vector>
#include <iostream>

class Solution
{
public:
    int countSubstrings(std::string s)
    {
        int count = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            int oddL = i - 1;
            int oddR = i + 1;

            while (oddL >= 0 && oddR < s.size())
            {
                if (s[oddL] == s[oddR])
                {
                    count += 1;
                    oddL -= 1;
                    oddR += 1;
                }
                else
                {
                    break;
                }
            }

            int evenL = i;
            int evenR = i + 1;

            while (evenL >= 0 && evenR < s.size())
            {
                if (s[evenL] == s[evenR])
                {
                    count += 1;
                    evenL -= 1;
                    evenR += 1;
                }
                else
                {
                    break;
                }
            }
        }
        return count;
    }
};

int main()
{
    std::string s = "aaa";
    Solution solution;
    std::cout << "number of palindromes: " << solution.countSubstrings(s) << std::endl;
    return 0;
}