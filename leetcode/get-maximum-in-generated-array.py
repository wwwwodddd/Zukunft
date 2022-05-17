class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        a = [0 for i in range(101)]
        a[0] = 0
        a[1] = 1
        for i in range(2,n+1):
            if i%2==0:
                a[i]=a[i//2]
            else:
                a[i]=a[i//2]+a[i//2+1]
        return max(a[:n+1])