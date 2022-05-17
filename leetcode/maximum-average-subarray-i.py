class Solution:
    def findMaxAverage(self, a: List[int], k: int) -> float:
        z = s = sum(a[:k])
        for i in range(k, len(a)):
            s += a[i] - a[i - k]
            z = max(z, s)
        return z / k