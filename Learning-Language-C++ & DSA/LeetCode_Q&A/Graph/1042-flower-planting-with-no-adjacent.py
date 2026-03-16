from collections import defaultdict
from typing import List

class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        
        # Build graph
        for x, y in paths:
            graph[x - 1].append(y - 1)
            graph[y - 1].append(x - 1)
        
        answer = [0] * n
        
        # Assign flowers greedily
        for i in range(n):
            used = set(answer[nei] for nei in graph[i] if answer[nei] != 0)
            
            for flower in range(1, 5):
                if flower not in used:
                    answer[i] = flower
                    break
        
        return answer