class Solution:
    def xorGame(self, a: List[int]) -> bool:
        z=0
        for i in a:
            z^=i
        return z==0 or len(a)%2==0