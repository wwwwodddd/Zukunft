class Solution:
    def lastStoneWeight(self, a: List[int]) -> int:
        while len(a) > 1:
            a.sort()
            a[-1] -= a[-2]
            del a[-2]
        return a[0]