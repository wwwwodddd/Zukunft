class Solution:
    def minimizeTheDifference(self, a: List[List[int]], t: int) -> int:
        s = {0}
        for r in a:
            s = {i + j for i in s for j in r}
        return min(abs(t - i) for i in s)