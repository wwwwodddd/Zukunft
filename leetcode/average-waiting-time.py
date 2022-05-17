class Solution:
    def averageWaitingTime(self, a: List[List[int]]) -> float:
        z=0
        t=0
        for x,y in a:
            t=max(t,x)+y
            z+=t-x
        return z/len(a)
            