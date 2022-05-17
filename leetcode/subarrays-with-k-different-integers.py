class Solution:
    def subarraysWithKDistinct(self, a: List[int], k: int) -> int:
        def zuo(k):
            c = Counter()
            z = 0
            j = 0
            for i in range(len(a)):
                if c[a[i]] == 0:
                    k -= 1
                c[a[i]] += 1
                while k < 0:
                    c[a[j]] -= 1
                    if c[a[j]] == 0:
                        k += 1
                    j += 1
                z += i - j + 1
            return z
        return zuo(k) - zuo(k-1)