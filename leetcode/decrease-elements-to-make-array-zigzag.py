class Solution:
    def movesToMakeZigzag(self, a: List[int]) -> int:
        x = 0
        for i in range(0, len(a), 2):
            t = 9**9
            if i > 0:
                t = min(t, a[i - 1])
            if i + 1 < len(a):
                t = min(t, a[i + 1])
            x += max(a[i] - (t - 1), 0)
        y = 0
        for i in range(1, len(a), 2):
            t = 9**9
            if i > 0:
                t = min(t, a[i - 1])
            if i + 1 < len(a):
                t = min(t, a[i + 1])
            y += max(a[i] - (t - 1), 0)
        return min(x, y)