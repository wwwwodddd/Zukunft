class Solution:
    def largestPerimeter(self, a: List[int]) -> int:
        z=0
        a.sort()
        for i in range(2,len(a)):
            if a[i-2]+a[i-1]>a[i]:
                z=max(z,a[i-2]+a[i-1]+a[i])
        return z