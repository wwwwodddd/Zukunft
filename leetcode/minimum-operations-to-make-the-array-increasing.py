class Solution:
    def minOperations(self, a: List[int]) -> int:
        z=0
        for i in range(1, len(a)):
            t=max(a[i-1]+1,a[i])
            z+=t-a[i]
            a[i]=t
        return z