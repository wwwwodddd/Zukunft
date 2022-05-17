class Solution:
    def hIndex(self, a: List[int]) -> int:
        a.sort(reverse=True)
        i = 0
        while i < len(a):
            if a[i] > i:
                i += 1
            else:
                break
        return i
