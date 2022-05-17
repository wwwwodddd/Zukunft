class Solution:
    def makeFancyString(self, s: str) -> str:
        t = '??'
        for i in s:
            if not t[-2] == t[-1] == i:
                t += i
        return t[2:]