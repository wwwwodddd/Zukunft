class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        def P(x):
            if x < 2:
                return False
            for i in range(2,x):
                if x % i == 0:
                    return False
            return True
        c = sum(P(i) for i in range(1, n + 1))
        return factorial(c) * factorial(n - c) % 1000000007