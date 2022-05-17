class Solution:
    def insert(self, a: List[List[int]], b: List[int]) -> List[List[int]]:
        x, y = b
        z = []
        for i, j in a:
            if j < x:
                z.append([i, j])
            if max(x, i) <= min(y, j):
                x = min(x, i)
                y = max(y, j)
        z.append([x, y])
        for i, j in a:
            if y < i:
                z.append([i, j])
        return z