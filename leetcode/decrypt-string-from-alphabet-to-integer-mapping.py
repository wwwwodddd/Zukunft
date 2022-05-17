class Solution:
    def freqAlphabets(self, s: str) -> str:
        z = ''
        i = len(s) - 1
        while i >= 0:
            if s[i] == '#':
                z += chr(96+int(s[i-2:i]))
                i -= 3
            else:
                z += chr(96+int(s[i]))
                i -= 1
        return z[::-1]