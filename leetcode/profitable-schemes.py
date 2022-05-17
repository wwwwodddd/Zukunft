class Solution:
    def profitableSchemes(self, n: int, m: int, a: List[int], b: List[int]) -> int:
        p=1000000007
        f=[[0 for i in range(n+1)]for j in range(m+1)]
        f[0][0]=1
        for x,y in zip(a,b):
            for i in range(x,n+1)[::-1]:
                for j in range(m+1):
                    f[min(j+y,m)][i]=(f[min(j+y,m)][i]+f[j][i-x])%p
        return sum(f[m])%p