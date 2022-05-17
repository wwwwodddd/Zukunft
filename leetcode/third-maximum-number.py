class Solution:
    def thirdMax(self, a: List[int]) -> int:
        a = sorted(list(set(a)))
        if len(a) > 2:
            return a[-3]
        else:
            return a[-1]