class Solution:
    def maxSumRangeQuery(self, b: List[int], requests: List[List[int]]) -> int:
        n = len(b)
        a = [0 for i in range(n + 1)]
        for x, y in requests:
            a[x] += 1
            a[y + 1] -= 1
        for i in range(n):
            a[i + 1] += a[i]
        a.pop()
        a.sort()
        b.sort()
        return sum(a[i]*b[i]for i in range(n))%1000000007