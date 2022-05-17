class Solution:
    def numOfWays(self, a: List[int]) -> int:
        z = factorial(len(a))
        def F(a):
            nonlocal z
            if a:
                z //= len(a)
                F([i for i in a if i < a[0]])
                F([i for i in a if i > a[0]])
        F(a)
        return (z - 1) % 1000000007