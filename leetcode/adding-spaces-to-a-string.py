class Solution:
    def addSpaces(self, s: str, a: List[int]) -> str:
        z = ''
        j = 0
        for i in range(len(s)):
            if j < len(a) and i == a[j]:
                z += ' '
                j += 1
            z += s[i]
        return z