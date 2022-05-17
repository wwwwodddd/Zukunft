class Solution:
    def addToArrayForm(self, a: List[int], k: int) -> List[int]:
        b = []
        while k:
            b.append(k % 10)
            k //= 10
        a = a[::-1]
        while len(a) < len(b):
            a.append(0)
        for i in range(len(b)):
            a[i] += b[i]
        for i in range(len(a)-1):
            a[i+1] += a[i] // 10
            a[i] %= 10
        while a[-1]>=10:
            a.append(a[-1] // 10)
            a[-2] %= 10
        return a[::-1]