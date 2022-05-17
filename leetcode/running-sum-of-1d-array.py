class Solution:
    def runningSum(self, a: List[int]) -> List[int]:
        for i in range(1, len(a)):
            a[i] += a[i - 1]
        return a