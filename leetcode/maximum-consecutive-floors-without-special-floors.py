class Solution:
    def maxConsecutive(self, b: int, t: int, a: List[int]) -> int:
        a.append(b - 1)
        a.append(t + 1)
        a.sort()
        z = 0
        for i in range(1, len(a)):
            z = max(z, a[i] - a[i - 1])
        return z - 1