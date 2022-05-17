class Solution:
    def validWordAbbreviation(self, s: str, t: str) -> bool:
        i = j = 0
        c = 0
        while j < len(t):
            if t[j].isdigit():
                if c == 0 and t[j] == '0':
                    return False
                c = c * 10 + int(t[j])
                j += 1
            else:
                i += c
                c = 0
                if i >= len(s):
                    return False
                if s[i] != t[j]:
                    return False
                i += 1
                j += 1
        i += c
        return i == len(s)