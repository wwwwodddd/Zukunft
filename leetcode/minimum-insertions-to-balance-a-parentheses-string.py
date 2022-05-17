class Solution:
    def minInsertions(self, s: str) -> int:
        z = c = 0
        for i in s:
            if i == '(':
                if c & 1:
                    c -= 1
                    z += 1
                c += 2
            else:
                c -= 1
                if c < 0:
                    c += 2
                    z += 1
        return z + c