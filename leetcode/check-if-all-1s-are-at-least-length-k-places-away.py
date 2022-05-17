class Solution:
    def kLengthApart(self, a: List[int], k: int) -> bool:
        b=[i for i in range(len(a))if a[i]==1]
        for i in range(1,len(b)):
            if b[i]-b[i-1]<=k:
                return False
        return True