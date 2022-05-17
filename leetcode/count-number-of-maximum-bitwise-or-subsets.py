class Solution:
    def countMaxOrSubsets(self, a: List[int]) -> int:
        z = 0
        c = 0
        for i in a:
            z |= i
        n = len(a)
        for i in range(1 << n):
            t = 0
            for j in range(n):
                if i >> j & 1:
                    t |= a[j]
            if t == z:
                c += 1
        return c