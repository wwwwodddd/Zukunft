class Solution:
    def largestMerge(self, x: str, y: str) -> str:
        if x == '' or y == '':
            return x + y
        if x > y:
            return x[0] + self.largestMerge(x[1:], y)
        else:
            return y[0] + self.largestMerge(x, y[1:])