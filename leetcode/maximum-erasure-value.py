class Solution:
    def maximumUniqueSubarray(self, a: List[int]) -> int:
        i = j = 0
        z = 0
        s = set()
        c = 0
        while i < len(a):
            while j < len(a) and a[j] not in s:
                s.add(a[j])
                c += a[j]
                j += 1
            z = max(z, c)
            s.remove(a[i])
            c -= a[i]
            i += 1
        return z