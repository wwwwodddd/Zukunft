class Solution:
    def isArmstrong(self, n: int) -> bool:
        k = len(str(n))
        return sum(int(i)**k for i in str(n)) == n