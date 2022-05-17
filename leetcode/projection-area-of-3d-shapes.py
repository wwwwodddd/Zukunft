class Solution:
    def projectionArea(self, a: List[List[int]]) -> int:
        z = 0
        for i in a:
            for j in i:
                if j > 0:
                    z += 1
        z += sum(map(max, a))
        z += sum(map(max, zip(*a)))
        return z