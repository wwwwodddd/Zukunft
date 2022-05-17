class Solution:
    def isCovered(self, a: List[List[int]], l: int, r: int) -> bool:
        b = [0] * 60
        for x, y in a:
            b[x] += 1
            b[y + 1] -= 1
        for i in range(1, 60):
            b[i] += b[i - 1]
        for i in range(l, r + 1):
            if b[i] == 0:
                return False
        return True