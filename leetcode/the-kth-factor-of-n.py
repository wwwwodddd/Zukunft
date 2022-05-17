class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        a = [i for i in range(1,n+1) if n%i==0]
        if k>len(a):
            return -1
        return a[k-1]