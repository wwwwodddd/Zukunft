class Solution:
    def maxChunksToSorted(self, a: List[int]) -> int:
        b=sorted((a[i],i)for i in range(len(a)))
        l=0
        z=1
        for i in range(len(b)):
            if l<i:
                z+=1
            l=max(l,b[i][1])
        return z