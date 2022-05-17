class Solution:
    def searchMatrix(self, a: List[List[int]], t: int) -> bool:
        n = len(a)
        m = len(a[0])
        L = 0
        R = n * m - 1
        while L <= R:
            M = (L + R) // 2
            if a[M // m][M % m] == t:
                return True
            if a[M // m][M % m] > t:
                R = M - 1
            else:
                L = M + 1
        return False