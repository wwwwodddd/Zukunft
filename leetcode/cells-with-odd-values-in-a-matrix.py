class Solution:
    def oddCells(self, m: int, n: int, d: List[List[int]]) -> int:
        a, b = map(Counter, zip(*d))
        a = sum(a[i] % 2 for i in a)
        b = sum(b[i] % 2 for i in b)
        return (m - a) * b + (n - b) * a