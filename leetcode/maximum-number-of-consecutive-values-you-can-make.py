class Solution:
    def getMaximumConsecutive(self, a: List[int]) -> int:
        s = 0
        for i in sorted(a):
            if i > s + 1:
                break
            s += i
        return s + 1