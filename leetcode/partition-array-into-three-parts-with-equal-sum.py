class Solution:
    def canThreePartsEqualSum(self, a: List[int]) -> bool:
        s = sum(a)
        if s % 3:
            return False
        x = s // 3
        c = 1
        t = 0
        for i in a:
            t += i
            if t == c * x:
                c += 1
        return c >= 4