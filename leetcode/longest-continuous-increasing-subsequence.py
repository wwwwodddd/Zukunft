class Solution:
    def findLengthOfLCIS(self, a: List[int]) -> int:
        z = c = 0
        l = -10**10
        for i in a:
            if l < i:
                c += 1
                z = max(z, c)
            else:
                c = 1
            l = i
        return z