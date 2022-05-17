class Solution:
    def longestWord(self, a: List[str]) -> str:
        z = ''
        s = ['']
        a.sort()
        for i in a:
            while len(s[-1]) >= len(i):
                s.pop()
            if len(s[-1]) + 1 == len(i) and s[-1] == i[:-1]:
                s.append(i)
                z = max(z, i, key=len)
        return z