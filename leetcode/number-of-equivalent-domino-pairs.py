class Solution:
    def numEquivDominoPairs(self, a: List[List[int]]) -> int:
        c = [0 for i in range(100)]
        z = 0
        for x, y in a:
            if x > y:
                x, y = y, x
            z += c[x * 10 + y]
            c[x * 10 + y] += 1
        return z