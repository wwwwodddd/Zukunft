class Solution:
    def largestTriangleArea(self, a: List[List[int]]) -> float:
        z = 0
        for x0,y0 in a:
            for x1,y1 in a:
                for x2,y2 in a:
                    z = max(z, abs((x1-x0)*(y2-y0)-(x2-x0)*(y1-y0)))
        return z/2