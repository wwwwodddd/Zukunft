class Solution:
    def rotate(self, a: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(a)
        for i in range(n//2):
            for j in range((n+1)//2):
                a[i][j], a[j][n-1-i], a[n-1-i][n-1-j], a[n-1-j][i] = a[n-1-j][i], a[i][j], a[j][n-1-i], a[n-1-i][n-1-j]
        return a