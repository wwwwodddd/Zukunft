class Solution:
    def sortArrayByParityII(self, a: List[int]) -> List[int]:
        n = len(a)
        j = 1
        for i in range(0, n, 2):
            if a[i] % 2 == 1:
                while a[j] % 2 == 1:
                    j += 2
                a[i], a[j] = a[j], a[i]
        return a