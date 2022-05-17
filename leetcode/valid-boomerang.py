class Solution:
    def isBoomerang(self, a: List[List[int]]) -> bool:
        x1 = a[1][0] - a[0][0]
        x2 = a[2][0] - a[0][0]
        y1 = a[1][1] - a[0][1]
        y2 = a[2][1] - a[0][1]
        return x1 * y2 - x2 * y1 != 0