class Solution:
    def minIncrementForUnique(self, a: List[int]) -> int:
        z=0
        l=-1
        a.sort()
        for i in a:
            if l<i:
                l=i
            else:
                z+=l+1-i
                l+=1
        return z