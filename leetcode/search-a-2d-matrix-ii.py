class Solution:
    def searchMatrix(self, a: List[List[int]], t: int) -> bool:
        x = 0
        y = len(a[0]) - 1
        while x < len(a) and y >= 0:
            if a[x][y] == t:
                return True
            if a[x][y] > t:
                y -= 1
            else:
                x += 1
        return False