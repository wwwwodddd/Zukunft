class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        f=Counter()
        f[(0,0)]=1
        for i in range(n):
            g=Counter()
            for x,c in f:
                for y in range(6):
                    if x==y:
                        d=c+1
                    else:
                        d=1
                    if d<=rollMax[y]:
                        g[(y,d)]=(g[(y,d)]+f[(x,c)])%1000000007
            f=g
        return sum(f.values())%1000000007