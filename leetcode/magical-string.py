class Solution:
    def magicalString(self, n: int) -> int:
        a = [1, 2, 2]
        for i in range(2, n):
            a += [i % 2 + 1] * a[i]
        return a[:n].count(1)