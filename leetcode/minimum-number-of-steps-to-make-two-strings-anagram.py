class Solution:
    def minSteps(self, s: str, t: str) -> int:
        s = Counter(s)
        t = Counter(t)
        return sum(max(t[i]-s[i],0)for i in t)