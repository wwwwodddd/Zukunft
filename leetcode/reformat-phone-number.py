class Solution:
    def reformatNumber(self, s: str) -> str:
        s = s.replace(' ', '').replace('-','')
        z = ''
        i = 0
        while i + 4 < len(s):
            z += s[i:i+3] + '-'
            i += 3
        if i + 4 == len(s):
            z += s[i:i+2] + '-' + s[i+2:i+4]
        else:
            z += s[i:]
        return z