class Solution:
    def countHomogenous(self, s: str) -> int:
        z = 0
        l = ''
        c = 0
        for i in s:
            if l != i:
                l = i
                c = 0
            c += 1
            z += c
        return z % 1000000007