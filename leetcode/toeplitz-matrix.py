class Solution:
    def isToeplitzMatrix(self, a: List[List[int]]) -> bool:
        n = len(a)
        m = len(a[0])
        for i in range(1,n):
            for j in range(1,m):
                if a[i][j] != a[i-1][j-1]:
                    return False
        return True