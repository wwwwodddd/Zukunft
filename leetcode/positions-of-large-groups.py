class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        x = 0
        z = []
        for i in range(len(s)):
            if i == len(s) - 1 or s[i] != s[i + 1]:
                if i - x >= 2:
                    z.append((x, i))
                x = i + 1
        return z