class Solution:
    def minCost(self, a: List[List[int]]) -> int:
        f = a[0]
        for i in range(1, len(a)):
            f = [a[i][0] + min(f[1], f[2]), a[i][1] + min(f[0], f[2]), a[i][2] + min(f[0], f[1])]
        return min(f)