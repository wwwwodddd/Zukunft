class Solution:
    def minimumPerimeter(self, n: int) -> int:
        for i in range(1, 100000):
            if i * (i + 1) * (2 * i + 1) * 2 >= n:
                return i * 8