class Solution:
    def findPoisonedDuration(self, a: List[int], d: int) -> int:
        z = 0
        l = -d
        for i in a:
            z += i + d - max(i, l)
            l = i + d
        return z