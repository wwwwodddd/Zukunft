class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        f = [[set()for j in range(len(s) + 1)] for i in range(len(s) + 1)]
        f[0][0].add('')
        for i in range(len(s)):
            for j in range(i + 1):
                for t in f[i][j]:
                    f[i + 1][j].add(t)
                    if s[i] == '(':
                        f[i + 1][j + 1].add(t + s[i])
                    elif s[i] == ')':
                        if j > 0:
                            f[i + 1][j - 1].add(t + s[i])
                    else:
                        f[i + 1][j].add(t + s[i])
        l = max(len(t)for t in f[len(s)][0])
        return [t for t in f[len(s)][0]if len(t)==l]
