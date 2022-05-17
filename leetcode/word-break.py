class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        f = [False for i in range(len(s) + 1)]
        f[0] = True
        for i in range(1, len(s) + 1):
            for w in wordDict:
                if i >= len(w) and s[i - len(w):i] == w and f[i - len(w)]:
                    f[i] = True
        return f[len(s)]