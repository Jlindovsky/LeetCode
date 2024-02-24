""""
Difficulty: Hard
Topics: Depth-First Search, Breadth-First Search,Union Find, Graph, Sorting
Description:
You are given an integer n indicating there are n people numbered from 0 to n - 1.
You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei]
indicates that person xi and person yi have a meeting at timei.
A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.
Person 0 has a secret and initially shares the secret with a person firstPerson at time 0.
This secret is then shared every time a meeting takes place with a person that has the secret.
More formally, for every meeting, if a person xi has the secret at timei,
then they will share the secret with person yi, and vice versa.
The secrets are shared instantaneously. That is, a person may receive the secret and share
it with people in other meetings within the same time frame.
Return a list of all the people that have the secret after all the meetings have taken place.
You may return the answer in any order.
"""

from collections import defaultdict, deque
from typing import List

class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        #set with the firstPerson and 0
        known_set = set([0, firstPerson])
        #list to store groups of meetings sorted by time
        sorted_meetings = []
        # Sort meetings by time
        meetings.sort(key=lambda x: x[2])
        # Keep track of seen times to group meetings happening at the same time
        seen_time = set()
        # Group meetings by time
        for meeting in meetings:
            if meeting[2] not in seen_time:
                seen_time.add(meeting[2])
                sorted_meetings.append([])
            sorted_meetings[-1].append((meeting[0], meeting[1]))  # Append the meeting to the last group
        for meeting_group in sorted_meetings:
            #set to store people who know the secret for this meeting group
            people_know_secret = set()
            #graph of relationships between people in group
            graph = defaultdict(list)
            # graph intialization
            for p1, p2 in meeting_group:
                graph[p1].append(p2)
                graph[p2].append(p1)
                if p1 in known_set:
                    people_know_secret.add(p1)
                if p2 in known_set:
                    people_know_secret.add(p2)
            queue = deque(people_know_secret)  # queue with people who know the secret
            while queue:
                curr = queue.popleft()  # Get the current person from the queue
                known_set.add(curr)  # Add the current person to the set of people who know the secret
                # Traverse neighbors of the current person in the graph
                for neighbor in graph[curr]:
                    if neighbor not in known_set:  # If neighbor doesn't know the secret yet
                        known_set.add(neighbor)  # Add neighbor to the set of people who know the secret
                        queue.append(neighbor)  # Add neighbor to the queue for further traversal
        return list(known_set)
    
def main():
    n = 4
    meetings = [[3, 1, 3], [1, 2, 2], [0, 3, 3]]
    firstPerson = 3
    solution = Solution()

    result = solution.findAllPeople(n, meetings, firstPerson)
    print(f"meetings={meetings}, firstPerson={firstPerson}, secret knows = {result}")

if __name__ == "__main__":
    main()