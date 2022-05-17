class Solution:
    def triangleNumber(self, a: List[int]) -> int:
        a = [i for i in a if i]
        n = len(a)
        s = [0 for i in range(2001)]
        for i in range(n):
            for j in range(i):
                s[a[i] + a[j]] += 1
        for i in range(1, 2001):
            s[i] += s[i - 1]
        z = n * (n - 1) * (n - 2) // 6
        for i in a:
            z -= s[i]
        return z