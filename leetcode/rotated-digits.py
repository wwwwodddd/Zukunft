class Solution:
    def rotatedDigits(self, n: int) -> int:
        def good(n):
            n = list(map(int,str(n)))
            if 3 in n or 4 in n or 7 in n:
                return False
            if 2 not in n and 5 not in n and 6 not in n and 9 not in n:
                return False
            return True
        return sum(map(good, range(1, n + 1)))