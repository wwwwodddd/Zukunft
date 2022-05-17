class Solution:
    def eliminateMaximum(self, d: List[int], s: List[int]) -> int:
        a = sorted([(x - 1) // y for x, y in zip(d, s)])
        for i in range(len(a)):
            if a[i] < i:
                return i
        return len(a)