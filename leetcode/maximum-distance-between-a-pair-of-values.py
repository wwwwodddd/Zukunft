class Solution:
    def maxDistance(self, a: List[int], b: List[int]) -> int:
        i = 0
        z = 0
        for j in range(len(b)):
            while i < len(a) and a[i] > b[j]:
                i += 1
            if i == len(a):
                break
            z = max(z, j - i)
        return z