class Solution:
    def canPartitionKSubsets(self, a: List[int], k: int) -> bool:
        n = len(a)
        s = sum(a)
        if s % k:
            return False
        s //= k
        f = [False for i in range(2 ** n)]
        f[0] = True
        for i in range(2 ** n):
            if f[i]:
                t = 0
                for j in range(n):
                    if i >> j & 1:
                        t += a[j]
                t %= s
                for j in range(n):
                    if ~i >> j & 1:
                        if t + a[j] <= s:
                            f[i | 1 << j] = True
        return f[2 ** n - 1]