class Solution:

    def __init__(self, radius: float, x_center: float, y_center: float):
        self.r = radius
        self.x = x_center
        self.y = y_center

    def randPoint(self) -> List[float]:
        t = random.random() * 2 * pi
        r = random.random() ** 0.5 * self.r
        return (self.x + r * cos(t), self.y + r * sin(t))

# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()