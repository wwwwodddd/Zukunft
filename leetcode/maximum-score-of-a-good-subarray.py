class Solution:
    def maximumScore(self, a: List[int], k: int) -> int:
        n = len(a)
        l = k
        r = k
        z = mn = a[k]
        while l > 0 or r < len(a) - 1:
            if l == 0:
                r += 1
            elif r + 1 == len(a):
                l -= 1
            elif a[l - 1] < a[r + 1]:
                r += 1
            else:
                l -= 1
            mn = min(mn, a[l], a[r])
            z = max(z, mn * (r - l + 1))
        return z