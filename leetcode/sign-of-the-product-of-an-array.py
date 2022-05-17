class Solution:
    def arraySign(self, a: List[int]) -> int:
        if 0 in a:
            return 0
        z = 1
        for i in a:
            if i < 0:
                z = -z
        return z