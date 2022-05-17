class Solution:
    def twoSumLessThanK(self, a: List[int], k: int) -> int:
        z = -1
        for j in range(len(a)):
            for i in range(j):
                if a[i] + a[j] < k:
                    z = max(z, a[i] + a[j])
        return z