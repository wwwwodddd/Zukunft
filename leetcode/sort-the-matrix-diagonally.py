class Solution:
    def diagonalSort(self, a: List[List[int]]) -> List[List[int]]:
        n = len(a)
        m = len(a[0])
        c = [[]for i in range(n + m)]
        for i in range(n):
            for j in range(m):
                c[i - j].append(a[i][j])
        for i in range(n + m):
            c[i].sort(reverse=True)
        for i in range(n):
            for j in range(m):
                a[i][j] = c[i - j].pop()
        return a
