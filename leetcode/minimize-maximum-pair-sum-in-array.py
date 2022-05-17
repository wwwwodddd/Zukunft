class Solution:
    def minPairSum(self, a: List[int]) -> int:
        a.sort()
        return max(a[i] + a[-i-1] for i in range(len(a)))