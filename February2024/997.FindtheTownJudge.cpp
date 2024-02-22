/*
Difficulty: Easy
Topics: Array, Hash Table, Graph
Description:
In a town, there are n people labeled from 1 to n.
There is a rumor that one of these people is secretly the town judge.
If the town judge exists, then:
The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing
that the person labeled ai trusts the person labeled bi.
If a trust relationship does not exist in trust array, then such a trust relationship does not exist.
Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.
*/

#include <iostream>
#include <vector>
class Solution
{
public:
    int findJudge(int n, std::vector<std::vector<int>> &trust)
    {
        std::vector<int> bi(n + 1), ai(n + 1);
        std::fill(bi.begin(), bi.end(), n - 1);
        std::fill(ai.begin(), ai.end(), 0);
        for (int i = 0; i < trust.size(); ++i)
        {
            ai[trust[i][0]] = 1;
            bi[trust[i][1]] -= 1;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (bi[i] == 0 && ai[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    // sample array
    std::vector<std::vector<int>> trust = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
    int n = 4;
    // instance of the Solution class
    Solution solution;
    // the largest sum after partitioning
    int result = solution.findJudge(n, trust);
    std::cout << "Judge is: " << result << std::endl;
    return 0;
}