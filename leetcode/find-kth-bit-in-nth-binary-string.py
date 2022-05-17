class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        l = [0] * (n + 1)
        c = [0] * (n + 1)
        l[1] = 1
        for i in range(2, n + 1):
            l[i] = l[i-1] * 2 + 1
            c[i] = l[i-1] + 1
        z = 0
        k -= 1
        for i in range(1, n + 1)[::-1]:
            if k > l[i]:
                k = 2 * l[i] - k
                z ^= 1
            elif k == l[i]:
                return str(z ^ 1)
        return str(z)