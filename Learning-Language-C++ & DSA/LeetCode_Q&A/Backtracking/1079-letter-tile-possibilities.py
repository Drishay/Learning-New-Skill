from collections import Counter

class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        count = Counter(tiles)

        def backtrack():
            total = 0
            for c in count:
                if count[c] > 0:
                    # choose this character
                    total += 1
                    count[c] -= 1
                    total += backtrack()
                    # backtrack
                    count[c] += 1
            return total

        return backtrack()