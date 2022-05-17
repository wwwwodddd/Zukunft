class Solution:
    def maximumUnits(self, a: List[List[int]], m: int) -> int:
        a.sort(key=lambda x:-x[1])
        z=0
        for x,y in a:
            t=min(x,m)
            m-=t
            z+=t*y
        return z