class Solution:
    def shiftGrid(self, a: List[List[int]], k: int) -> List[List[int]]:
        n=len(a)
        m=len(a[0])
        for i in range(k):
            b=[[a[i][(j-1)%m]for j in range(m)]for i in range(n)]
            for j in range(n):
                b[(j+1)%n][0]=a[j][-1]
            a=b
        return a