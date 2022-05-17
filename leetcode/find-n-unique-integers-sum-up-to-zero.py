class Solution:
    def sumZero(self, n: int) -> List[int]:
        if n&1:
            return list(range(0-n//2,n//2+1))
        else:
            return list(range(-n//2,0))+list(range(1,n//2+1))
