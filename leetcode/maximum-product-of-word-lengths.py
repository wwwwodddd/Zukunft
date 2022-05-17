class Solution:
    def maxProduct(self, a: List[str]) -> int:
        b = [0 for i in range(len(a))]
        l = [len(i) for i in a]
        for i in range(len(a)):
            for j in a[i]:
                b[i] |= 1 << ord(j) - 97
        z = 0
        for i in range(len(a)):
            for j in range(i):
                if (b[i] & b[j]) == 0:
                    z = max(z, l[i] * l[j])
        return z