class Solution:
    def maxNiceDivisors(self, m: int) -> int:
        if m==1:
            return 1
        return pow(3,(m-2)//3,1000000007)*((m-2)%3+2)%1000000007