class Solution:
    def sortEvenOdd(self, a: List[int]) -> List[int]:
        b = sorted(a[1::2],reverse=True)
        c = sorted(a[0::2])
        d = []
        for i in range(len(c)):
            d.append(c[i])
            if i < len(b):
                d.append(b[i])
        return d