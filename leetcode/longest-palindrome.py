class Solution:
    def longestPalindrome(self, s: str) -> int:
        c = Counter(s)
        l = sum(c[i]//2*2 for i in c)
        if l < len(s):
            l += 1
        return l