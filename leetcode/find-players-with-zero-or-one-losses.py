class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        a = Counter()
        b = Counter()
        for x, y in matches:
            a[x] += 1
            a[y] += 1
            b[y] += 1
        s = []
        t = []
        for i in sorted(a):
            if b[i] == 0:
                s.append(i)
            if b[i] == 1:
                t.append(i)
        return s, t