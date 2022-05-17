class Solution:
    def numOfSubarrays(self, a: List[int], k: int, t: int) -> int:
        z = s = 0
        for i in range(len(a)):
            s += a[i] - t
            if i >= k - 1:
                if s >= 0:
                    z += 1
                s -= a[i - k + 1] - t
        return z