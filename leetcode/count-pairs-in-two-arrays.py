import sortedcontainers
class Solution:
    def countPairs(self, a: List[int], b: List[int]) -> int:
        s = sortedcontainers.SortedList()
        z = 0
        for i in range(len(a)):
            z += s.bisect_left(a[i] - b[i])
            s.add(b[i] - a[i])
        return z