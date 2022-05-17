class Solution:
    def countPairs(self, a: List[int], k: int) -> int:
        n = len(a)
        z = 0
        for j in range(n):
            for i in range(j):
                if a[i] == a[j] and i * j % k == 0:
                    z += 1
        return z