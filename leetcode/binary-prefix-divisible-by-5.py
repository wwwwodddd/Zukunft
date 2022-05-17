class Solution:
    def prefixesDivBy5(self, a: List[int]) -> List[bool]:
        r = 0
        b = []
        for i in a:
            r = (r * 2 + i) % 5
            b.append(r == 0)
        return b