class Solution:
    def rangeBitwiseAnd(self, l: int, r: int) -> int:
        if l == r:
            return l
        return self.rangeBitwiseAnd(l // 2, r // 2) * 2