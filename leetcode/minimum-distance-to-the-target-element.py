class Solution:
    def getMinDistance(self, a: List[int], target: int, start: int) -> int:
        z = 1e9
        for i in range(len(a)):
            if a[i] == target:
                z = min(z, abs(start - i))
        return z