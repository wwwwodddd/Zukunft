class Solution:
    def reductionOperations(self, a: List[int]) -> int:
        a.sort(reverse=True)
        z = 0
        for i in range(1, len(a)):
            if a[i-1] != a[i]:
                z += i
        return z