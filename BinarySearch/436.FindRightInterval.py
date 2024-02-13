""""
Difficulty: Medium
Topics: Array, Binary Search, Sorting
Description:
You are given an array of intervals,
where intervals[i] = [starti, endi] and each starti is unique.
The right interval for an interval i is an
interval j such that startj >= endi and startj is minimized. Note that i may equal j.
Return an array of right interval indices for each interval i.
If no right interval exists for interval i, then put -1 at index i.
"""

from ast import List

class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        result = [-1] * len(intervals)
        for i, interval in enumerate(intervals):
            interval.append(i)
        intervals.sort(key=lambda x: x[0])
        for i, interval in enumerate(intervals):
            target_end = interval[1]
            left, right = i, len(intervals) - 1
            while left <= right:
                mid = (left + right) // 2
                if intervals[mid][0] >= target_end:
                    result[interval[2]] = intervals[mid][2]
                    right = mid - 1
                else:
                    left = mid + 1
        return result
    
def main():

    solution = Solution()
    intervals = [[1,12],[2,9],[3,10],[13,14],[15,16],[16,17]]
    result = solution.findRightInterval(intervals)
    print(result)

if __name__ == "__main__":
    main()