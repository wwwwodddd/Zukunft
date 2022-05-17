class Solution:
    def getMaximumXor(self, a: List[int], b: int) -> List[int]:
        for i in range(1,len(a)):
            a[i]^=a[i-1]
        return [((1<<b)-1)^i for i in a[::-1]]