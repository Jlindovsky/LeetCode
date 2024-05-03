""""
Difficulty: Easy
Topics: Array, Hash Table, Divide and Conquer, Sorting, Counting
Description:
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.
"""

from ast import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        numCount = {}
        length = len(nums)/2
        for num in nums:
            numCount[num] = numCount.get(num, 0) +1
        for key, value in numCount.items():
            if value > length:
                return key

def main():
    solution = Solution()
    input_nums = [3, 3, 4, 2, 4, 4, 2, 4, 4]  # Example input array
    result = solution.majorityElement(input_nums)
    print("Majority element:", result)

if __name__ == "__main__":
    main()   
        