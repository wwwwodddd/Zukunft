class Solution:
    def binarySearchableNumbers(self, a: List[int]) -> int:
        n = len(a)
        v = [1 for i in range(n)]
        s = -1e9
        for i in range(n):
            if s < a[i]:
                s = a[i]
            else:
                v[i] = 0
        s = 1e9
        for i in range(n)[::-1]:
            if s > a[i]:
                s = a[i]
            else:
                v[i] = 0
        return sum(v)