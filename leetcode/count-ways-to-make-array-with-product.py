class Solution:

    def waysToFillArray(self, q: List[List[int]]) -> List[int]:
        p = 1000000007
        def C(n, m):
            z = 1
            for i in range(m):
                z = z * (n - i) // (i + 1)
            return z
        def gao(x, y):
            z = 1
            for i in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]:
                c = 0
                while x % i == 0:
                    c += 1
                    x //= i
                z = z * C(y + c - 1, c) % p
            if x > 1:
                z = z * y % p
            return z
        return [gao(y, x) for x, y in q]