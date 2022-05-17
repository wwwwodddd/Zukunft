class Solution:
    def printVertically(self, s: str) -> List[str]:
        a = s.split()
        l = max(map(len, a))
        b = ['' for i in range(l)]
        for i in range(len(a)):
            for j in range(len(a[i])):
                b[j] += a[i][j]
            for j in range(len(a[i]), l):
                b[j] += ' '
        return [i.rstrip() for i in b]