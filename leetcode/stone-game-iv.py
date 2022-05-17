class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        f = [0 for i in range(n+1)]
        for i in range(1,n+1):
            j=1
            while j*j<=i:
                if f[i-j*j]==0:
                    f[i]=1
                j+=1
        return f[n]