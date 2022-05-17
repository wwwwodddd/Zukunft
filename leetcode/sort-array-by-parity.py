class Solution:
    def sortArrayByParity(self, a: List[int]) -> List[int]:
        n = len(a)
        i = 0
        j = n-1
        while True:
            while i < n and a[i] % 2 == 0:
                i += 1
            while j >= 0 and a[j] % 2 == 1:
                j -= 1
            if i < j:
                a[i], a[j] = a[j], a[i]
            else:
                break
        return a