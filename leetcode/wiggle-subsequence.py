class Solution:
    def wiggleMaxLength(self, a: List[int]) -> int:
        f = g = 1
        l = a[0]
        for i in a[1:]:
            if i > l:
                f = max(f, g + 1)
            elif i < l:
                g = max(g, f + 1)
            l = i
        return max(f, g)