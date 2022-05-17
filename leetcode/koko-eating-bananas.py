class Solution:
    def minEatingSpeed(self, a: List[int], h: int) -> int:
        L=0
        R=max(a)
        while L<R-1:
            M=(L+R)//2
            if sum((i+M-1)//M for i in a)<=h:
                R=M
            else:
                L=M
        return R