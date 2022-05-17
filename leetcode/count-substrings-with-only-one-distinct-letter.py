class Solution:
    def countLetters(self, s: str) -> int:
        l = ''
        c = 0
        z = 0
        for i in s:
            if l == i:
                c += 1
            else:
                l = i
                c = 1
            z += c
        return z