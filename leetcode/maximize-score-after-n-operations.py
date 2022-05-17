class Solution:
    def maxScore(self, a: List[int]) -> int:
        n = len(a)
        f = [0 for i in range(1 << n)]
        for i in range(1 << n):
            c = bin(i).count('1')
            if c & 1:
                continue
            for j in range(n):
                if ~i >> j & 1:
                    for k in range(j):
                        if ~i >> k & 1:
                            f[i | 1 << j | 1 << k] = max(f[i | 1 << j | 1 << k], f[i] + (c // 2 + 1) * gcd(a[j], a[k]))
        return f[2 ** n - 1]
