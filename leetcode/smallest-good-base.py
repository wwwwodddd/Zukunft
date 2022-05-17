class Solution:
    def smallestGoodBase(self, n: str) -> str:
        n=int(n)
        for m in range(1,99)[::-1]:
            L,R=0,n
            while L<R-1:
                M=(L+R)//2
                if M**m>n-1:
                    R=M
                else:
                    L=M
            if L>1 and L**(m+1)-1==n*(L-1):
                return str(L)