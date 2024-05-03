""""
Difficulty: Medium
Topics: Array, Hash Table, Greedy, Sorting, Counting
Description:
Given an array of integers arr and an integer k.
Find the least number of unique integers after removing exactly k elements.
"""

from ast import List

class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        numCount = {}
        for num in arr:
            numCount[num] = numCount.get(num, 0) +1
        numCount =  dict(sorted(numCount.items(), key=lambda x: x[1]))
        result = len(numCount)
        for num, count in numCount.items():
            if k >= count:
                k -=count
                result -=1
            else:
                break
        return result

def main():

    solution = Solution()
    arr = [4,3,1,1,3,3,2]
    k = 3
    result = solution.findLeastNumOfUniqueInts(arr, k)
    print("number of unique integers after deletion: ", result)

if __name__ == "__main__":
    main()