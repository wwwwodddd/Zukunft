class Solution:
    def maxTurbulenceSize(self, a: List[int]) -> int:
        z = c = 1
        for i in range(1, len(a)):
            if a[i] > a[i-1] and (c==1 or a[i-1] < a[i-2]) or a[i] < a[i-1] and (c==1 or a[i-1] > a[i-2]):
                c += 1
            elif a[i] != a[i-1]:
                c = 2
            else:
                c = 1
            z = max(z, c)
        return z