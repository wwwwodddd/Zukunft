class Solution:
    def getMaxLen(self, a: List[int]) -> int:
        x=-9**9
        y=-9**9
        z=0
        for i in a:
            if i>0:
                x,y=max(x+1,1),y+1
            elif i<0:
                x,y=y+1,max(x+1,1)         
            else:
                x=-9**9
                y=-9**9
            z=max(z,x)
        return z