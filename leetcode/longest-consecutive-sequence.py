class Solution:
    def longestConsecutive(self, a: List[int]) -> int:
        s = set(a)
        z = 0
        for i in s:
            if i - 1 not in s:
                j = i
                while j in s:
                    j += 1
                z = max(z, j - i)
        return z