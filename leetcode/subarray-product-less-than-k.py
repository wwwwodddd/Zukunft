class Solution:
    def numSubarrayProductLessThanK(self, a: List[int], k: int) -> int:
        z = 0
        s = 1
        i = j = 0
        while i < len(a):
            s *= a[i]
            i += 1
            while j < i and s >= k:
                s //= a[j]
                j += 1
            z += i - j
        return z