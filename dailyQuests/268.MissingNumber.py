""""
Difficulty: Easy
Topics: Array, Hash Table, Math, Binary Search, Bit Manipulation, Sorting
Description:
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.
"""

from ast import List

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums.sort()
        numCount = [-1] * (len(nums)+1) 
        for num in nums:
            numCount[num] = num
        for i, num in enumerate(numCount):
            if num == -1:
                return i

        return len(nums) +1
    


def main():

    solution = Solution()
    nums = [9,6,4,2,3,5,7,0,1]
    result = solution.missingNumber(nums)
    print("missing Number is: ", result)

if __name__ == "__main__":
    main()