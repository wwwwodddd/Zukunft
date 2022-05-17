class Solution:
    def gcdOfStrings(self, s: str, t: str) -> str:
        if s + t == t + s:
            return s[:gcd(len(s),len(t))]
        else:
            return ''