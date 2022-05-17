class Solution:
    def largestOverlap(self, a: List[List[int]], b: List[List[int]]) -> int:
        n = len(a)
        z = 0
        for di in range(-n,n):
            for dj in range(-n,n):
                c = 0
                for i in range(n):
                    for j in range(n):
                        ni = i + di
                        nj = j + dj
                        if 0 <= ni < n and 0 <= nj < n:
                            if a[i][j] == b[ni][nj] == 1:
                                c += 1
                z = max(z, c)
        return z