class Solution:
    def countServers(self, a: List[List[int]]) -> int:
        r = list(map(sum, a))
        c = list(map(sum, zip(*a)))
        z = 0
        for i in range(len(a)):
            for j in range(len(a[0])):
                if a[i][j] == 1 and (r[i] > 1 or c[j] > 1):
                    z += 1
        return z