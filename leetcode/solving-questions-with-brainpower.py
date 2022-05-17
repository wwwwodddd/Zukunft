class Solution:
    def mostPoints(self, q: List[List[int]]) -> int:
        n = len(q)
        f = [0 for i in range(n + 1)]
        for i in range(n)[::-1]:
            f[i] = max(f[i + 1], q[i][0] + f[min(i + q[i][1] + 1, n)])
        return f[0]