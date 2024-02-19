""""
Difficulty: Hard
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

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        booked = [0] * n
        times = [0] * n
        meetings.sort()

        for i, j in meetings:
            available = False
            min_index = -1
            min_time = float('inf')
            for k in range(n):
                if times[k] < min_time:
                    min_time = times[k]
                    min_index = k
                if times[k] <= i:
                    available = True
                    booked[k] += 1
                    times[k] = j
                    break
            if not available:
                booked[min_index] += 1
                times[min_index] += (j - i)

        max_booked = -1
        max_id = -1
        for k in range(n):
            if booked[k] > max_booked:
                max_booked = booked[k]
                max_id = k
        return max_id
