class Solution:
    def maxBoxesInWarehouse(self, a: List[int], b: List[int]) -> int:
        d = b[:]
        for i in range(1, len(b)):
            b[i] = min(b[i], b[i - 1])
        for i in range(len(d) - 1)[::-1]:
            d[i] = min(d[i], d[i + 1])
        for i in range(len(b)):
            b[i] = max(b[i], d[i])
        a.sort()
        b.sort()
        j = 0
        for i in b:
            if j < len(a) and a[j] <= i:
                j += 1
        return j
