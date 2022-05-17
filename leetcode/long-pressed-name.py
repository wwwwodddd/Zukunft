class Solution:
    def isLongPressedName(self, s: str, t: str) -> bool:
        i = 0
        j = 0
        while True:
            if i == len(s) and j == len(t):
                return True
            elif j == len(t):
                return False
            elif i < len(s) and s[i] == t[j]:
                i += 1
                j += 1
            elif j > 0 and t[j] == t[j - 1]:
                j += 1
            else:
                return False