""""
Difficulty: Medium
Topics: Dynamic Programming, Depth-First Search, Breadth-First Search, Graph, Heap, Shortest Path
Shortest Path
Description:
There are n cities connected by some number of flights.
You are given an array flights where flights[i] = [fromi, toi, pricei]
indicates that there is a flight from city fromi to city toi withcost pricei.
You are also given three integers src, dst, and k, return the cheapest
price from src to dst with at most k stops. If there is no such route, return -1.
"""

from typing import List
import heapq

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph = {}
        for u, v, w in flights:
            if u not in graph:
                graph[u] = []
            graph[u].append((v, w))
        pq = [(0, src, 0)]
        visited = set()
        while pq:
            price, city, stops = heapq.heappop(pq)
            if city == dst:
                return price
            if stops <= k and (city, stops) not in visited:
                visited.add((city, stops))
                neighbors = graph.get(city, [])
                for neighbor, cost in neighbors:
                    new_price = price + cost
                    heapq.heappush(pq, (new_price, neighbor, stops + 1))
        return -1

def main():
    n = 13
    flights = [[11,12,74],[1,8,91],[4,6,13],[7,6,39],[5,12,8],[0,12,54],[8,4,32],[0,11,4],[4,0,91],[11,7,64],[6,3,88],[8,5,80],[11,10,91],[10,0,60],[8,7,92],[12,6,78],[6,2,8],[4,3,54],[3,11,76],[3,12,23],[11,6,79],[6,12,36],[2,11,100],[2,5,49],[7,0,17],[5,8,95],[3,9,98],[8,10,61],[2,12,38],[5,7,58],[9,4,37],[8,6,79],[9,0,1],[2,3,12],[7,10,7],[12,10,52],[7,2,68],[12,2,100],[6,9,53],[7,4,90],[0,5,43],[11,2,52],[11,8,50],[12,4,38],[7,9,94],[2,7,38],[3,7,88],[9,12,20],[12,0,26],[10,5,38],[12,8,50],[0,2,77],[11,0,13],[9,10,76],[2,6,67],[5,6,34],[9,7,62],[5,3,67]]
    src = 10
    dst = 1
    k = 10

    solution = Solution()
    print(solution.findCheapestPrice(n, flights, src, dst, k))

if __name__ == "__main__":
    main()