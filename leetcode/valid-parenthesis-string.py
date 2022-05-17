class Solution:
    def checkValidString(self, s: str) -> bool:
        l, h = 0, 0
        for i in s:
            if i == '(':
                l += 1
                h += 1
            elif i == '*':
                l = max(l - 1, 0)
                h += 1
            else:
                l = max(l - 1, 0)
                h -= 1
                if h < 0:
                    return False
        return l == 0
                