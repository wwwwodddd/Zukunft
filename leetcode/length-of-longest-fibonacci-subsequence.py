class Solution:
    def lenLongestFibSubseq(self, a: List[int]) -> int:
        s = set(a)
        z = 0
        for j in range(len(a)):
            for i in range(j):
                x, y, c = a[i], a[j], 2
                if y - x < x and y - x in s:
                    continue
                while x + y in s:
                    x, y, c = y, x + y, c + 1
                    z = max(z, c)
        return z