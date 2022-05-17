class Solution:
    def sumFourDivisors(self, a: List[int]) -> int:
        m = 100000
        b = [0] * (m + 1)
        s = [0] * (m + 1)
        for i in range(1, m + 1):
            for j in range(i, m + 1, i):
                b[j] += 1
                s[j] += i
        return sum(s[i] for i in a if b[i]==4)