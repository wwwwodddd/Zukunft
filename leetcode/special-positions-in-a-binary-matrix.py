class Solution:
    def numSpecial(self, a: List[List[int]]) -> int:
        n=len(a)
        m=len(a[0])
        r=[0 for i in range(n)]
        c=[0 for j in range(m)]
        for i in range(n):
            for j in range(m):
                r[i]+=a[i][j]
                c[j]+=a[i][j]
        z=0
        for i in range(n):
            for j in range(m):
                if r[i]==c[j]==a[i][j]==1:
                    z+=1
        return z
