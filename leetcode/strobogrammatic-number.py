class Solution:
    def isStrobogrammatic(self, s: str) -> bool:
        t = ''
        for i in s:
            if i in '018':
                t += i
            elif i in '69':
                t += str(15 - int(i))
            else:
                return False
        return s == t[::-1]