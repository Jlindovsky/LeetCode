""""
Difficulty: Medium
Topics: Array, Greedy, Heap
Description:
You are given an integer array heights representing the
heights of buildings, some bricks, and some ladders.
You start your journey from building 0 and move to the
next building by possibly using bricks or ladders.
While moving from building i to building i+1 (0-indexed),
If the current building's height is greater than or equal to
the next building's height, you do not need a ladder or bricks.
If the current building's height is less than the next building's height,
you can either use one ladder or (h[i+1] - h[i]) bricks.
"""

from ast import List
import heapq

class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        longestPQ = []
        heightSum = 0
        for i in range(len(heights) - 1):
            height = heights[i+1] - heights[i]
            if height > 0:
                heapq.heappush(longestPQ, height)
                if len(longestPQ) > ladders:
                    heightSum += heapq.heappop(longestPQ)
                if heightSum > bricks:
                    return i
        return len(heights) -1
    
def main():

    solution = Solution()
    heights = [4,12,2,7,3,18,20,3,19]
    bricks = 10
    ladders = 2
    result = solution.furthestBuilding(heights, bricks, ladders)
    print("Furthest reachable building: ", result)

if __name__ == "__main__":
    main()