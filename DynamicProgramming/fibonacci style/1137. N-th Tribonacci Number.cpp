/*
Difficulty: Easy
Description:
The Tribonacci sequence Tn is defined as follows:
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
Given n, return the value of Tn.
 */

#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int tribonacci(int n)
    {
        std::vector<int> f(n + 1, 0);
        if (n > 0)
        {
            f[1] = 1;
        }
        if (n > 1)
        {
            f[2] = 1;
        }

        for (int i = 3; i <= n; i++)
        {
            f[i] = f[i - 1] + f[i - 2] + f[i - 3];
        }
        return f[n];
    }
};

int main()
{
    int num = 0;
    std::cin >> num;
    // instance of the Solution class
    Solution solution;
    // sorted sequential digits within the specified range
    int result = solution.tribonacci(num);

    std::cout << result;

    return 0;
}