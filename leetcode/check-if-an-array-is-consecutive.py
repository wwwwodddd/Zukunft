class Solution:
    def isConsecutive(self, a: List[int]) -> bool:
        a.sort()
        for i in range(1, len(a)):
            if a[i] != a[i - 1] + 1:
                return False
        return True