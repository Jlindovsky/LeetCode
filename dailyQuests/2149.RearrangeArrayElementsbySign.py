""""
Difficulty: Medium
Topics: Array, Two Pointers, Simulation
Description:
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
You should rearrange the elements of nums such that the modified array follows the given conditions:
Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
"""

from ast import List

class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        numsP = []
        numsN = []
        result = []

        for num in nums:
            if num >= 0:
                numsP.append(num)
            else:
                numsN.append(num)
        for i in range(len(numsP)):
            result.append(numsP[i])
            result.append(numsN[i])
        return result
            

def main():

    solution = Solution()
    nums= [-2, -2, 1, 5, 3,-7]
    result = solution.rearrangeArray(nums)
    print("sorted by Sign:", result)

if __name__ == "__main__":
    main()
      
