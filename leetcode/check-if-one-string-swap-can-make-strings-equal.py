class Solution:
    def areAlmostEqual(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        if s==t:
            return True
        d=[(i,j)for i,j in zip(s,t)if i!=j]
        return len(d)==2 and d[0][0]==d[1][1] and d[0][1]==d[1][0]