class Solution:
    def minNumberOperations(self, a: List[int]) -> int:
        z = 0
        l = 0
        for i in a:
            z += max(i - l, 0)
            l = i
        return z