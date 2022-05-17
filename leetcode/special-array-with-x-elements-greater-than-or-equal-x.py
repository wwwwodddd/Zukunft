class Solution:
    def specialArray(self, a: List[int]) -> int:
        a.sort()
        a = [0] + a
        for i in range(1, len(a)):
            if a[i-1] < len(a) - i <= a[i]:
                return len(a) - i
        return -1