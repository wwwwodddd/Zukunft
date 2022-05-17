class Solution:
    def numberOfDays(self, y: int, m: int) -> int:
        a = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        if y % 400 == 0 or y % 100 != 0 and y % 4 == 0:
            a[1] += 1
        return a[m - 1]