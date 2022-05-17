class Solution:
    def maxIncreaseKeepingSkyline(self, a: List[List[int]]) -> int:
        n = len(a)
        b = [max(a[i][j]for j in range(n)) for i in range(n)]
        c = [max(a[j][i]for j in range(n)) for i in range(n)]
        s = 0
        for i in range(n):
            for j in range(n):
                s += min(b[i], c[j]) - a[i][j]
        return s