class Solution:
    f = []
    def F(self, x):
        if self.f[x]==x:
            return x
        return self.F(self.f[x])
    def findCircleNum(self, a: List[List[int]]) -> int:
        n=len(a)
        self.f=[i for i in range(n)]
        z=n
        for i in range(n):
            for j in range(n):
                if a[i][j]==1:
                    x = self.F(i)
                    y = self.F(j)
                    if x!=y:
                        self.f[x]=y
                        z-=1
        return z
            