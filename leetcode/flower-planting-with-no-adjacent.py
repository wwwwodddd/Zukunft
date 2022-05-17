class Solution:
    def gardenNoAdj(self, n: int, e: List[List[int]]) -> List[int]:
        a = [[] for i in range(n)]
        for x, y in e:
            x -= 1
            y -= 1
            if x < y:
                x, y = y, x
            a[x].append(y)
        z = [1 for i in range(n)]
        for i in range(n):
            s = {z[j] for j in a[i]}
            while z[i] in s:
                z[i] += 1
        return z