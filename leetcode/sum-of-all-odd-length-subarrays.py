class Solution:
    def sumOddLengthSubarrays(self, a: List[int]) -> int:
        n = len(a)
        z = 0
        for i in range(n):
            z += ((i + 1) * (n - i) + 1) // 2 * a[i]
        return z