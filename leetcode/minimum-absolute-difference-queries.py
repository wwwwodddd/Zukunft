class Solution:
    def minDifference(self, a: List[int], q: List[List[int]]) -> List[int]:
        s = [[0 for i in range(101)]]
        for i in a:
            s.append(s[-1].copy())
            s[-1][i] += 1
        z = []
        for x, y in q:
            b = [i for i in range(101) if s[x][i] != s[y+1][i]]
            t = 101
            for i in range(1, len(b)):
                t = min(t, b[i] - b[i - 1])
            if t == 101:
                t = -1
            z.append(t)
        return z
            