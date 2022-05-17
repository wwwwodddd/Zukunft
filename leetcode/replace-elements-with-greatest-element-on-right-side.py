class Solution:
    def replaceElements(self, a: List[int]) -> List[int]:
        for i in range(len(a) - 1)[::-1]:
            a[i] = max(a[i], a[i + 1])
        return a[1:] + [-1]