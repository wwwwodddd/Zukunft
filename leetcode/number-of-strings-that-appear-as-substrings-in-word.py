class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        c = 0
        for i in patterns:
            if i in word:
                c += 1
        return c