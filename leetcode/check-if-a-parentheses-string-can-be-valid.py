class Solution:
    def canBeValid(self, s: str, t: str) -> bool:
        x = y = 0
        for i in range(len(s)):
            if t[i] == '0':
                y += 1
                if x > 0:
                    x -= 1
                else:
                    x += 1
            elif s[i] == '(':
                y += 1
                x += 1
            elif s[i] == ')':
                y -= 1
                if x > 0:
                    x -= 1
                else:
                    x += 1
                if x > y:
                    return False
        return x == 0