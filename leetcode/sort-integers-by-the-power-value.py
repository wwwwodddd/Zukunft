def F(x):
    if x == 1:
        return 0
    elif x % 2 == 0:
        return F(x // 2) + 1
    else:
        return F(x * 3 + 1) + 1

class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        a = [(F(i),i) for i in range(lo,hi+1)]
        a.sort()
        return a[k-1][1]