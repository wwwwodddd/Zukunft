class Solution:
    def isPrefixString(self, s: str, w: List[str]) -> bool:
        return s=='' or len(w)>0 and s.startswith(w[0]) and self.isPrefixString(s[len(w[0]):], w[1:])