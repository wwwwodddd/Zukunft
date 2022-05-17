class Solution:
    def numMagicSquaresInside(self, a: List[List[int]]) -> int:
        n = len(a)
        m = len(a[0])
        z = 0
        def dui(b):
            return len(set(b))==9 and min(b)==1 and max(b)==9 and sum(b[0::3])==sum(b[1::3])==sum(b[2::3])==sum(b[0:3])==sum(b[3:6])==sum(b[6:9])==b[0]+b[4]+b[8]==b[2]+b[4]+b[6]
        for i in range(n-2):
            for j in range(m-2):
                b = []
                for k in range(3):
                    for l in range(3):
                        b.append(a[i + k][j + l])
                if dui(b):
                    z += 1
        return z