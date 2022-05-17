class Solution:
    def maximumTop(self, a: List[int], k: int) -> int:
        if len(a) == 1:
            return [a[0], -1][k & 1]
        return max(a[:max(k-1,0)] + a[k:k+1])