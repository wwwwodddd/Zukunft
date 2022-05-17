class Solution:
    def maxBoxesInWarehouse(self, a: List[int], b: List[int]) -> int:
        for i in range(1, len(b)):
            b[i] = min(b[i], b[i - 1])
        a.sort()
        j = 0
        for i in b[::-1]:
            if j < len(a) and a[j] <= i:
                j += 1
        return j