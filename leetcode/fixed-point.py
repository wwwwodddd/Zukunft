class Solution:
    def fixedPoint(self, a: List[int]) -> int:
        for i in range(len(a)):
            if a[i] == i:
                return i
        return -1