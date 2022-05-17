class Solution:
    def minStartValue(self, a: List[int]) -> int:
        z = 0
        s = 0
        for i in a:
            s += i
            z = min(z, s)
        return -z + 1