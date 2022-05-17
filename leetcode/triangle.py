class Solution:
    def minimumTotal(self, a: List[List[int]]) -> int:
        n = len(a)
        for i in range(n-1)[::-1]:
            for j in range(i+1):
                a[i][j]+=min(a[i+1][j],a[i+1][j+1])
        return a[0][0]