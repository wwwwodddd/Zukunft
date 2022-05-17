class Solution:
    def matrixScore(self, a: List[List[int]]) -> int:
        n=len(a)
        m=len(a[0])
        for i in range(n):
            if a[i][0]==0:
                for j in range(m):
                    a[i][j]^=1
        c=[sum(i)for i in zip(*a)]
        return sum(max(n-c[j],c[j])<<(m-1-j)for j in range(m))