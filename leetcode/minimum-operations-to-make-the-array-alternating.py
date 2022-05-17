class Solution:
    def minimumOperations(self, a: List[int]) -> int:
        c = list(Counter(a[0::2]).most_common(3))
        d = list(Counter(a[1::2]).most_common(3))
        c += [(0, 0), (-1, 0)]
        d += [(0, 0), (-1, 0)]
        z = len(a)
        for cv, cc in c:
            for dv, dc in d:
                if cv != dv:
                    z = min(z, len(a) - cc - dc)
        return z