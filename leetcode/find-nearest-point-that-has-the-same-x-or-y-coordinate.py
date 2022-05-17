class Solution:
    def nearestValidPoint(self, x: int, y: int, a: List[List[int]]) -> int:
        zi = -1
        zd = 1e9
        for i in range(len(a)):
            if a[i][0] == x or a[i][1] == y:
                d = abs(a[i][0] - x) + abs(a[i][1] - y)
                if zd > d:
                    zd = d
                    zi = i
        return zi
                    