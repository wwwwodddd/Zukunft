class Solution:
    def commonChars(self, s: List[str]) -> List[str]:
        r = []
        for i in set(s[0]):
            r += [i] * min(j.count(i) for j in s)
        return r