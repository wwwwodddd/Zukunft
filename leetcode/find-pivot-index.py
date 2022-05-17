class Solution:
    def pivotIndex(self, a: List[int]) -> int:
        s=sum(a)
        t=0
        for i in range(len(a)):
            s-=a[i]
            if s==t:
                return i
            t+=a[i]
        return -1