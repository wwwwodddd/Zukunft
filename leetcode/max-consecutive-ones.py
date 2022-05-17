class Solution:
    def findMaxConsecutiveOnes(self, a: List[int]) -> int:
        z = c = 0
        for i in a:
            if i == 1:
                c += 1
                z = max(z, c)
            else:
                c = 0
        return z