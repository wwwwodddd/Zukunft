class Solution:
    def divideArray(self, a: List[int]) -> bool:
        a.sort()
        return a[::2] == a[1::2]