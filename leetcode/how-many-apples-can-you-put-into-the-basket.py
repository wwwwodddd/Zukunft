class Solution:
    def maxNumberOfApples(self, a: List[int]) -> int:
        z = 0
        s = 5000
        for i in sorted(a):
            if s >= i:
                s -= i
                z += 1
        return z