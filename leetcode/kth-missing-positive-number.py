class Solution:
    def findKthPositive(self, a: List[int], k: int) -> int:
        a = [0] + a + [9999]
        for i in range(1, len(a)):
            if k>a[i]-a[i-1]-1:
                k-=a[i]-a[i-1]-1
            else:
                return a[i-1]+k