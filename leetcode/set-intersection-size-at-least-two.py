class Solution:
    def intersectionSizeTwo(self, a: List[List[int]]) -> int:
        a.sort(key=lambda x:(x[1], -x[0]))
        x, y, z = -1, -1, 0
        for l, r in a:
            if x < l:
                x, y, z = y, r, z + 1
            if x < l:
                x, z = r - 1, z + 1
        return z