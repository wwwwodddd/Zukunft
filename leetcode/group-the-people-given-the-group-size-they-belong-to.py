class Solution:
    def groupThePeople(self, a: List[int]) -> List[List[int]]:
        n = len(a)
        b = [[] for i in range(n + 1)]
        for i in range(n):
            b[a[i]].append(i)
        z = []
        for i in range(1, n + 1):
            for j in range(0, len(b[i]), i):
                z.append(b[i][j:j+i])
        return z