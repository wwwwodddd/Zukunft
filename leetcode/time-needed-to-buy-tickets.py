class Solution:
    def timeRequiredToBuy(self, a: List[int], k: int) -> int:
        z = 0
        for i in range(len(a)):
            if i <= k:
                z += min(a[i], a[k])
            else:
                z += min(a[i], a[k]-1)
        return z