class Solution:
    def getDescentPeriods(self, a: List[int]) -> int:
        z = c = l = 0
        for i in a:
            if i == l - 1:
                c += 1
            else:
                c = 1
            z += c
            l = i
        return z