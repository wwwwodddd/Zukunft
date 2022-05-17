class Solution:
    def sumEvenAfterQueries(self, a: List[int], q: List[List[int]]) -> List[int]:
        s = 0
        for i in a:
            if i % 2 == 0:
                s += i
        z = []
        for x, y in q:
            if a[y] % 2 == 0:
                s -= a[y]
            a[y] += x
            if a[y] % 2 == 0:
                s += a[y]
            z.append(s)
        return z