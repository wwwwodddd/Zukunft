class Solution:
    def longestStrChain(self, a: List[str]) -> int:
        f = {}
        for s in sorted(a, key=len):
            f[s] = max(f.get(s[:i] + s[i+1:], 0) + 1 for i in range(len(s)))
        return max(f.values())