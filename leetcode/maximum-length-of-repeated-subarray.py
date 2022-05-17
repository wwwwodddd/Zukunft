class Solution:
    def findLength(self, a: List[int], b: List[int]) -> int:
        n = len(a)
        m = len(b)
        f = [[0 for j in range(m+1)]for i in range(n+1)]
        z = 0
        for i in range(1,n+1):
            for j in range(1,m+1):
                if a[i-1] == b[j-1]:
                    f[i][j] = f[i-1][j-1]+1
                    z = max(z, f[i][j])
                else:
                    f[i][j] = 0
        return z
