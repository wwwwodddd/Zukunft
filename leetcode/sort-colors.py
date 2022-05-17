class Solution:
    def sortColors(self, a: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0
        for j in range(len(a)):
            if a[j] == 0:
                a[i], a[j] = a[j], a[i]
                i += 1
        for j in range(len(a)):
            if a[j] == 1:
                a[i], a[j] = a[j], a[i]
                i += 1
        return a