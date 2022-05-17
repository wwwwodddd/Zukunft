class Solution:
    def getHint(self, s: str, t: str) -> str:
        x = 0
        for i in range(len(s)):
            if s[i] == t[i]:
                x += 1
        s = Counter(s)
        t = Counter(t)
        y = -x
        for i in s:
            y += min(s[i], t[i])
        return '%dA%dB' % (x, y)