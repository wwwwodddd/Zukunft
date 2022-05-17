class Solution:
    def totalMoney(self, n: int) -> int:
        return sum(1+i//7+i%7 for i in range(n))