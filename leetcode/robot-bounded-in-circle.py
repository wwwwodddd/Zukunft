class Solution:
    def isRobotBounded(self, s: str) -> bool:
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        x = y = d = 0
        for i in 4 * s:
            if i == 'G':
                x += dx[d]
                y += dy[d]
            elif i == 'L':
                d = (d - 1) % 4
            else:
                d = (d + 1) % 4
        return x == 0 == y