class Solution:
    def findLongestChain(self, a: List[List[int]]) -> int:
        a.sort()
        l = -10000
        c = 0
        for x, y in a:
            if l < x:
                c += 1
                l = y
            elif l > y:
                l = y
        return c