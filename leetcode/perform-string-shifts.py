class Solution:
    def stringShift(self, s: str, a: List[List[int]]) -> str:
        z = 0
        for x, y in a:
            if x == 0:
                z += y
            else:
                z -= y
        z %= len(s)
        s = s[z:] + s[:z]
        return s