class Solution:
    def countPoints(self, points: List[List[int]], queries: List[List[int]]) -> List[int]:
        return [sum((u-x)**2+(v-y)**2<=r**2 for u,v in points)for x,y,r in queries]