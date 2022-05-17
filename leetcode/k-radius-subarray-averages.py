class Solution:
    def getAverages(self, a: List[int], k: int) -> List[int]:
        z = [-1 for i in a]
        s = sum(a[:2*k])
        for i in range(k, len(a) - k):
            s += a[i + k]
            z[i] = s // (2 * k + 1)
            s -= a[i - k]
        return z