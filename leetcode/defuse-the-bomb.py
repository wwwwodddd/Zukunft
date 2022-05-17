class Solution:
    def decrypt(self, a: List[int], k: int) -> List[int]:
        n = len(a)
        a += a
        for i in range(1, len(a)):
            a[i] += a[i - 1]
        if k == 0:
            return [0] * n
        elif k > 0:
            return [a[i+k]-a[i]for i in range(n)]
        else:
            return [a[n+i-1]-a[n+i-1+k]for i in range(n)]