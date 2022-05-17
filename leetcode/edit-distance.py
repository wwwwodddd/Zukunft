class Solution:
    def minDistance(self, a: str, b: str) -> int:
        f = [[i+j for i in range(len(b)+1)]for j in range(len(a)+1)]
        for i in range(1, len(a)+1):
            for j in range(1, len(b)+1):
                if a[i-1]==b[j-1]:
                    f[i][j] = f[i-1][j-1]
                else:
                    f[i][j] = min(f[i-1][j-1],f[i-1][j],f[i][j-1])+1
        return f[len(a)][len(b)]