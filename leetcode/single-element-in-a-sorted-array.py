class Solution:
    def singleNonDuplicate(self, a: List[int]) -> int:
        i = 0
        j = 2 ** 20
        while j > 1:
            if i + j < len(a) and a[i + j - 1] == a[i + j - 2]:
                i += j
            j //= 2
        return a[i]