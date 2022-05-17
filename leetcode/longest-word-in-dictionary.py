class Solution:
    def longestWord(self, a: List[str]) -> str:
        a.sort()
        s = ['']
        z = ''
        for i in a:
            while len(s[-1]) >= len(i):
                s.pop()
            if s[-1]==i[:-1]:
                s.append(i)
                if len(z) < len(i):
                    z = i
        return z
            