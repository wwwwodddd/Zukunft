class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        a = []
        i = c = 0
        for j in range(len(s)):
            if s[j] == '1':
                c += 1
            else:
                c -= 1
            if c == 0:
                a.append('1' + self.makeLargestSpecial(s[i + 1: j]) + '0')
                i = j + 1
        return ''.join(sorted(a)[::-1])