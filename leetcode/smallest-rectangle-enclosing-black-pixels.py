class Solution:
    def minArea(self, a: List[List[str]], x: int, y: int) -> int:
        n = len(a)
        m = len(a[0])
        U1 = -1
        D1 = x
        U2 = x
        D2 = n
        
        L1 = -1
        R1 = y
        L2 = y
        R2 = m
        
        while U1 < D1 - 1:
            M = (U1 + D1) // 2
            for i in range(m):
                if a[M][i] == '1':
                    D1 = M
                    break
            else:
                U1 = M
        
        while U2 < D2 - 1:
            M = (U2 + D2) // 2
            for i in range(m):
                if a[M][i] == '1':
                    U2 = M
                    break
            else:
                D2 = M
        
        while L1 < R1 - 1:
            M = (L1 + R1) // 2
            for i in range(n):
                if a[i][M] == '1':
                    R1 = M
                    break
            else:
                L1 = M
        
        while L2 < R2 - 1:
            M = (L2 + R2) // 2
            for i in range(n):
                if a[i][M] == '1':
                    L2 = M
                    break
            else:
                R2 = M
        return (L2 - R1 + 1) * (U2 - D1 + 1)
                