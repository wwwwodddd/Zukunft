class Solution:
    def missingNumber(self, a: List[int]) -> int:
        d = (a[-1] - a[0]) // len(a)
        for i in range(len(a)):
            if a[i] != a[0] + i * d:
                return a[0] + i * d
        return a[0]