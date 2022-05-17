class Solution:
    def maxChunksToSorted(self, a: List[int]) -> int:
        l=0
        z=1
        for i in range(len(a)):
            if l<i:
                z+=1
            l=max(l,a[i])
        return z