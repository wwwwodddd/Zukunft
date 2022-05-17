class Solution:
    def longestCommonSubsequence(self, a: List[List[int]]) -> List[int]:
        z = []
        n = len(a)
        p = [0 for i in a]
        while True:
            mn = 100
            for i in range(n):
                if p[i] == len(a[i]):
                    return z
                mn = min(mn, a[i][p[i]])
            c = 0
            for i in range(n):
                if a[i][p[i]] == mn:
                    c += 1
            if c == n:
                z.append(mn)
                for i in range(n):
                    p[i] += 1
            else:
                for i in range(n):
                    if a[i][p[i]] == mn:
                        p[i] += 1