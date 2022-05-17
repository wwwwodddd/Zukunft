class Solution:
    def sortSentence(self, s: str) -> str:
        a = s.split()
        b = [i for i in a]
        for i in a:
            b[int(i[-1])-1] = i[:-1]
        return ' '.join(b)