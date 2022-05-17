class Solution:
    def numSteps(self, s: str) -> int:
        c = 0
        z = 0
        for i in s[:0:-1]:
            c += int(i)
            z += 1 + c % 2
            c = (c + 1) // 2
        c += int(s[0])
        z += c // 2
        return z