class Solution:
    def isPathCrossing(self, p: str) -> bool:
        x, y = 0, 0
        s = set()
        s.add((x, y))
        for i in p:
            if i == 'N':
                y += 1
            elif i == 'S':
                y -= 1
            elif i == 'E':
                x += 1
            elif i == 'W':
                x -= 1
            if (x, y) in s:
                return True
            s.add((x, y))
        return False