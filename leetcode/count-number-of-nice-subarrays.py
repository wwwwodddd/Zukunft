class Solution:
    def numberOfSubarrays(self, a: List[int], k: int) -> int:
        def zuo(k):
            z = 0
            j = 0
            for i in range(len(a)):
                k -= a[i] % 2
                while k < 0:
                    k += a[j] % 2
                    j += 1
                z += i - j + 1
            return z
        return zuo(k) - zuo(k-1)