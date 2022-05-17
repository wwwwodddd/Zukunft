class Solution:
    def longestValidParentheses(self, s: str) -> int:
        z = 0
        b = [-1]
        for i in range(len(s)):
            if s[i] == '(':
                b.append(i)
            else:
                b.pop()
                if len(b) == 0:
                    b = [i]
                z = max(z, i - b[-1])
        return z