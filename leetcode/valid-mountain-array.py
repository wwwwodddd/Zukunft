class Solution:
    def validMountainArray(self, a: List[int]) -> bool:
        if len(a) < 2:
            return False
        p = a.index(max(a))
        if p == 0 or p == len(a) - 1:
            return False
        for i in range(p):
            if a[i] >= a[i+1]:
                return False
        for i in range(p+1, len(a)):
            if a[i-1] <= a[i]:
                return False
        return True