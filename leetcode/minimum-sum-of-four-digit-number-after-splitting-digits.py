class Solution:
    def minimumSum(self, s: int) -> int:
        s = str(s)
        s = list(s)
        s.sort()
        s = list(map(int, s))
        return 10*(s[0]+s[1])+s[2]+s[3]
