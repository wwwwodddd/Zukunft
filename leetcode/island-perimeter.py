class Solution(object):
    def islandPerimeter(self, grid):
        m = len(grid[0])
        grid = [[0] * m] + grid + [[0] * m]
        n = len(grid)
        for i in range(n):
            grid[i] = [0] + grid[i] + [0]
        n = len(grid)
        m = len(grid[0])
        ans = 0
        for i in range(n):
            for j in range(m - 1):
                if grid[i][j] != grid[i][j + 1]:
                    ans += 1
        for i in range(n - 1):
            for j in range(m):
                if grid[i + 1][j] != grid[i][j]:
                    ans += 1
        return ans
        """
        :type grid: List[List[int]]
        :rtype: int
        """