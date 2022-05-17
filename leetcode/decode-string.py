class Solution:
    def decodeString(self, s: str) -> str:
        p = 0
        i = 0
        z = ''
        while i < len(s):
            if s[i].isalpha():
                z += s[i]
                i += 1
            elif s[i].isdigit():
                p = p * 10 + int(s[i])
                i += 1
            elif s[i] == '[':
                j = i
                c = 0
                while True:
                    if s[j] == '[':
                        c += 1
                    elif s[j] == ']':
                        c -= 1
                        if c == 0:
                            break
                    j += 1
                z += self.decodeString(s[i+1:j]) * p
                p = 0
                i = j + 1
        return z