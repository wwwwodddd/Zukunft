class Solution:
    def findSpecialInteger(self, a: List[int]) -> int:
        t = len(a) // 4
        for i in range(len(a)):
            if a[i] == a[i + t]:
                return a[i]