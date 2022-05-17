class Solution:
    def diagonalSum(self, a: List[List[int]]) -> int:
        n = len(a)
        z = 0
        for i in range(n):
            for j in range(n):
                if i == j or i + j == n - 1:
                    z += a[i][j]
        return z