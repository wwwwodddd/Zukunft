class Solution:
    def largestRectangleArea(self, a: List[int]) -> int:
        s = []
        z = 0
        def push(x, y):
            nonlocal z
            w = 0
            while len(s) and s[-1][0] >= x:
                w += s[-1][1]
                z = max(z, s[-1][0] * w)
                s.pop()
            s.append((x, w + y))
        for i in a:
            push(i, 1)
        push(0, 0)
        return z