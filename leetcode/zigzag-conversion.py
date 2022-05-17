class Solution:
    def convert(self, s: str, n: int) -> str:
        if n == 1:
            return s
        a = [[]for i in range(n)]
        for i in range(len(s)):
            j = i % (2 * (n - 1))
            if j >= n:
                j = 2 * (n - 1) - j
            a[j].append(s[i])
        z = ''
        for i in a:
            z += ''.join(i)
        return z