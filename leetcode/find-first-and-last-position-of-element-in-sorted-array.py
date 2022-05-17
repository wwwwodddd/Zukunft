class Solution:
    def searchRange(self, a: List[int], x: int) -> List[int]:
        l = bisect.bisect_left(a, x)
        r = bisect.bisect_right(a, x)
        if l == r:
            l, r = -1, -1
        else:
            r -= 1
        return [l, r]