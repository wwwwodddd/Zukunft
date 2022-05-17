class Solution:
    def duplicateZeros(self, a: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        i = len(a) + a.count(0) - 1
        j = len(a) - 1
        while i >= 0:
            if a[j] == 0:
                if i < len(a):
                    a[i] = a[j]
                i -= 1
            if i < len(a):
                a[i] = a[j]
            i -= 1
            j -= 1
        return a