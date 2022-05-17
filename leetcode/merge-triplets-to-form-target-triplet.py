class Solution:
    def mergeTriplets(self, s: List[List[int]], t: List[int]) -> bool:
        x = y = z = 0
        for a, b, c in s:
            if a <= t[0] and b <= t[1] and c <= t[2]:
                x = max(x, a)
                y = max(y, b)
                z = max(z, c)
        return [x, y, z] == t