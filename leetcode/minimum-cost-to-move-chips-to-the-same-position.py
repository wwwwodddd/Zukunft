class Solution:
    def minCostToMoveChips(self, a: List[int]) -> int:
        c=[0,0]
        for i in a:
            c[i%2]+=1
        return min(c)