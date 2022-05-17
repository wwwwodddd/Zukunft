class Solution:
    def numSubmatrixSumTarget(self, a: List[List[int]], t: int) -> int:
        n = len(a)
        m = len(a[0])
        s = [[0 for j in range(m + 1)]for i in range(n + 1)]
        for i in range(n):
            for j in range(m):
                s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + a[i][j]
        z = 0
        for i in range(n + 1):
            for j in range(i):
                c = Counter()
                for k in range(m + 1):
                    r = s[i][k] - s[j][k]
                    z += c[r - t]
                    c[r] += 1
        return z
                    
