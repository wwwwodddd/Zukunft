class Solution:
    def maxDepth(self, s: str) -> int:
        z = 0
        c = 0
        for i in s:
            if i == '(':
                c += 1
                z = max(z, c)
            if i == ')':
                c -= 1
        return z