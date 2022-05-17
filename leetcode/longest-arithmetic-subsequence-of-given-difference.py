class Solution:
    def longestSubsequence(self, a: List[int], d: int) -> int:
        f = Counter()
        for i in a:
            f[i] = f[i - d] + 1
        return max(f.values())