class Solution:
    def findErrorNums(self, a: List[int]) -> List[int]:
        n = len(a)
        x = sum(i for i in a)-n*(n+1)//2
        y = sum(i*i for i in a)-n*(n+1)*(2*n+1)//6
        z = y // x
        return [(z + x) // 2, (z - x) // 2]