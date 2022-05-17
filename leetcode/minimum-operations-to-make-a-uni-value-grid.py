class Solution:
    def minOperations(self, a: List[List[int]], x: int) -> int:
        b = []
        n = len(a)
        for i in range(n):
            b += a[i]
        for i in range(len(b)):
            if b[i] % x != b[0] % x:
                return -1
        for i in range(len(b)):
            b[i] //= x
        b.sort()
        z = 0
        for i in range(len(b)):
            z += abs(b[i] - b[len(b) // 2])
        return z