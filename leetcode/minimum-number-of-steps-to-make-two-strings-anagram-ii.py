class Solution:
    def minSteps(self, s: str, t: str) -> int:
        s = Counter(s)
        t = Counter(t)
        return sum(abs(s[i] - t[i])for i in set(s) | set(t))            