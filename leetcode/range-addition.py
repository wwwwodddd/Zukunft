class Solution:
    def getModifiedArray(self, n: int, e: List[List[int]]) -> List[int]:
        a = [0 for i in range(n + 1)]
        for x, y, z in e:
            y += 1
            a[x] += z
            a[y] -= z
        for i in range(n):
            a[i + 1] += a[i]
        a.pop()
        return a