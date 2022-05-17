class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        k += 1
        f = [[9**9 for j in range(n)] for i in range(k + 1)]
        f[0][src] = 0
        for i in range(k):
            for x, y, z in flights:
                f[i + 1][y] = min(f[i + 1][y], f[i][x] + z)
        ans = min(f[i][dst] for i in range(k + 1))
        if ans == 9**9:
            ans = -1
        return ans