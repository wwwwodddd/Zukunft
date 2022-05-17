class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        m=1
        s=0
        for i in str(n):
            m*=int(i)
            s+=int(i)
        return m-s