import sortedcontainers
class Solution:
    def reversePairs(self, a: List[int]) -> int:
        s = sortedcontainers.SortedList()
        z = 0
        for i in a[::-1]:
            z += s.bisect_left(i)
            s.add(2 * i)
        return z