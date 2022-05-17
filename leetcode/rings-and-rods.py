class Solution:
    def countPoints(self, s: str) -> int:
        a = [0] * 10
        for i in range(0, len(s), 2):
            a[int(s[i + 1])] |= 1 << 'RGB'.index(s[i])
        return a.count(7)