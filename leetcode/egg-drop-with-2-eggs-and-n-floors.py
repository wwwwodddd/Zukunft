class Solution:
    def twoEggDrop(self, n: int) -> int:
        for i in range(100):
            if n > i:
                n -= i
            else:
                return i