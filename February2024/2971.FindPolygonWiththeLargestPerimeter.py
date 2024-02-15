""""
Difficulty: Medium
Topics: Array, Greedy, Sorting, Prefix Sum
Description:
You are given an array of positive integers nums of length n.
A polygon is a closed plane figure that has at least 3 sides.
The longest side of a polygon is smaller than the sum of its other sides.
Conversely, if you have k (k >= 3) positive real numbers a1, a2, a3, ...,
ak where a1 <= a2 <= a3 <= ... <= ak and a1 + a2 + a3 + ... + ak-1 > ak,
then there always exists a polygon with k sides whose lengths are a1, a2, a3, ..., ak.
The perimeter of a polygon is the sum of lengths of its sides.
Return the largest possible perimeter of a polygon whose sides can be formed from nums,
or -1 if it is not possible to create a polygon.
"""

from ast import List

class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums = sorted(nums)
        sublist_sum = 0
        length = len(nums)
        for i in range(length):
            sublist_sum = sum(nums[0:length - i -1])
            if sublist_sum > nums[length - 1 - i]:
                return sublist_sum + nums[length - 1 - i]
        return -1
    
def main():

    solution = Solution()
    nums= [1,12,1,2,5,50,3]
    result = solution.largestPerimeter(nums)
    print("Largest possible perimeter:", result)

if __name__ == "__main__":
    main()
      