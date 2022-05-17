class Solution:
    def largestOddNumber(self, s: str) -> str:
        s = list(s)
        while len(s)and s[-1]in'24680':
            s.pop()
        return ''.join(s)