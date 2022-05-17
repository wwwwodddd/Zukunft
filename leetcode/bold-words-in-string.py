class Solution:
    def boldWords(self, w: List[str], s: str) -> str:
        n = len(s)
        v = [0 for i in range(n + 1)]
        for b in w:
            for i in range(len(b), len(s) + 1):
                if s[i - len(b) : i] == b:
                    for j in range(len(b)):
                        v[i - len(b) + j] = 1
        z = ''
        for i in range(len(s)):
            if v[i - 1] == 0 and v[i] == 1:
                z += '<b>'
            z += s[i]
            if v[i] == 1 and v[i + 1] == 0:
                z += '</b>'
        return z