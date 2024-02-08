/*
Difficulty: Easy
Topics: Math, Dynamic Programming, Recursion, Memoization
Description:
The Fibonacci numbers, commonly denoted F(n) form a sequence,
called the Fibonacci sequence, such that each number is
the sum of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).
 */

#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int fib(int n)
    {
        if (n < 1)
            return n;
        // vector size of n+1 filled with zeros
        std::vector<int> F(n + 1, 0);
        F[0] = 0;
        F[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            // to dp[i] we can come from previous step
            // or from one from previous, thats why we need to add them
            F[i] = F[i - 1] + F[i - 2];
        }

        return F[n];
    }
};

int main()
{
    int num = 0;
    std::cin >> num;
    // instance of the Solution class
    Solution solution;
    // sorted sequential digits within the specified range
    int result = solution.fib(num);

    std::cout << result;

    return 0;
}