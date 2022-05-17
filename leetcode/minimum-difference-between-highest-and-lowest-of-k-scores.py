class Solution:
    def minimumDifference(self, a: List[int], k: int) -> int:
        a=sorted(a)
        return min(a[i+k-1]-a[i]for i in range(len(a)-k+1))