class Solution:
    def clumsy(self, n: int) -> int:
        s=''
        for i in range(n):
            s+=['-','*','//','+'][i%4]+str(n-i)
        return eval('-'+s)