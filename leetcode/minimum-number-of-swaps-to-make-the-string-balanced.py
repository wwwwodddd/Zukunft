class Solution:
    def minSwaps(self, s: str) -> int:
        c = 0
        for i in s:
            if i == '[':
                c += 1
            elif i == ']':
                c = max(c - 1, 0)
        return (c + 1) // 2
                