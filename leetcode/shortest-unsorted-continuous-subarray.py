class Solution:
    def findUnsortedSubarray(self, a: List[int]) -> int:
        b = sorted(a)
        if a == b:
            return 0
        i = 0
        j = len(a) - 1
        while a[i] == b[i]:
            i += 1
        while a[j] == b[j]:
            j -= 1
        return j - i + 1