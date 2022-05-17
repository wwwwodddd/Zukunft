class Solution:
    def checkStraightLine(self, a: List[List[int]]) -> bool:
        for x,y in a:
            if(a[1][0]-a[0][0])*(y-a[0][1])-(x-a[0][0])*(a[1][1]-a[0][1])!=0:
                return False
        return True