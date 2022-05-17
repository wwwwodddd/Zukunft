class Solution:
    def minOperations(self, a: List[int]) -> int:
        n = len(a)
        a = sorted(set(a))
        b = []
        for i in a:
            b.append((i, 1))
            b.append((i + n, -1))
        b.sort()
        z = s = 0
        for x, y in b:
            s += y
            z = max(z, s)
        return n - z