import sortedcontainers
class Solution:
    def countRangeSum(self, a: List[int], l: int, u: int) -> int:
        s = sortedcontainers.SortedList()
        z = t = 0
        s.add(t)
        for i in a:
            t += i
            z += s.bisect(t - l) - s.bisect_left(t - u)
            s.add(t)
        return z