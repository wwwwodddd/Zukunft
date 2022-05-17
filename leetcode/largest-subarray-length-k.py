class Solution:
    def largestSubarray(self, a: List[int], k: int) -> List[int]:
        n = len(a)
        x = max(a[:n-k+1])
        p = a.index(x)
        return a[p:p+k]