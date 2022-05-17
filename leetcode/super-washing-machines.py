class Solution:
    def findMinMoves(self, a: List[int]) -> int:
        s = sum(a)
        n = len(a)
        if s % n:
            return -1
        z = t = 0
        for i in a:
            t += i - s // n
            z = max(z, abs(t), i - s // n)
        return z