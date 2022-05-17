import bisect
class Solution:
    def search(self, a: List[int], t: int) -> int:
        i = bisect.bisect_left(a, t)
        if i < len(a) and a[i] == t:
            return i
        else:
            return -1