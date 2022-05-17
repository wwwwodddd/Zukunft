class Solution:
    def kthLargestValue(self, a: List[List[int]], k: int) -> int:
        n = len(a)
        m = len(a[0])
        for i in range(n):
            for j in range(1, m):
                a[i][j] ^= a[i][j - 1]
        for i in range(1, n):
            for j in range(m):
                a[i][j] ^= a[i - 1][j]
        b = []
        for i in a:
            b += i
        b.sort()
        return b[-k]