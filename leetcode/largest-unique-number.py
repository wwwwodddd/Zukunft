class Solution:
    def largestUniqueNumber(self, a: List[int]) -> int:
        c = Counter(a)
        b = [i for i in c if c[i] == 1]
        if len(b) == 0:
            return -1
        return max(b)
