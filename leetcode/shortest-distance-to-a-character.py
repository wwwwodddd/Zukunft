class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        n=len(s)
        z=[n]*n
        for i in range(n):
            if s[i]==c:
                z[i]=0
        for i in range(1,n):
            z[i]=min(z[i],z[i-1]+1)
        for i in range(n-1)[::-1]:
            z[i]=min(z[i],z[i+1]+1)
        return z
