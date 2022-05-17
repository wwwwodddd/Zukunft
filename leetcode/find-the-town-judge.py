class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        c = [0 for i in range(n+1)]
        d = [0 for i in range(n+1)]
        for x,y in trust:
            c[x]+=1
            d[y]+=1
        z = [i for i in range(1,n+1) if c[i] == 0 and d[i] == n-1]
        if len(z) == 1:
            return z[0]
        else:
            return -1