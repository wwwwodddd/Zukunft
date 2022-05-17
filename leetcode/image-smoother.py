class Solution:
    def imageSmoother(self, a: List[List[int]]) -> List[List[int]]:
        n = len(a)
        m = len(a[0])
        b = [[0 for j in range(m)]for i in range(n)]
        for i in range(n):
            for j in range(m):
                c = s = 0
                for k in range(i-1,i+2):
                    for l in range(j-1,j+2):
                        if 0 <= k < n and 0 <= l < m:
                            s += a[k][l]
                            c += 1
                b[i][j] = s // c
        return b