class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        a, b, c = sorted([a, b, c])
        if c - a == 2:
            z = [0]
        elif b - a <= 2 or c - b <= 2:
            z = [1]
        else:
            z = [2]
        z.append(c - a - 2)
        return z