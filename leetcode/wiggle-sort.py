class Solution:
    def wiggleSort(self, a: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        f = 0
        for i in range(1, len(a)):
            if i & 1:
                if a[i] < a[i - 1]:
                    a[i], a[i - 1] = a[i - 1], a[i]
            else:
                if a[i] > a[i - 1]:
                    a[i], a[i - 1] = a[i - 1], a[i]
        return a