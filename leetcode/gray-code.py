class Solution:
    def grayCode(self, n: int) -> List[int]:
        a = [0]
        for i in range(n):
            for j in range(2**i):
                a.append(a[2**i-1-j]+2**i)
        return a