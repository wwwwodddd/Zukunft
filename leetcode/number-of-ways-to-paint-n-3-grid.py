class Solution:
    def numOfWays(self, n: int) -> int:
        f=[0 for i in range(n+1)] # abc
        g=[0 for i in range(n+1)] # aba
        f[1]=1
        g[1]=1
        p=1000000007
        for i in range(2,n+1):
            f[i]=(2*f[i-1]+2*g[i-1])%p
            g[i]=(2*f[i-1]+3*g[i-1])%p
        return 6*(f[n]+g[n])%p