class Solution:
    def minAvailableDuration(self, a: List[List[int]], b: List[List[int]], d: int) -> List[int]:
        i = 0
        j = 0
        a.sort()
        b.sort()
        while i < len(a) and j < len(b):
            if max(a[i][0], b[j][0]) + d <= min(a[i][1], b[j][1]):
                return [max(a[i][0], b[j][0]), max(a[i][0], b[j][0]) + d]
            if a[i][1] < b[j][1]:
                i += 1
            else:
                j += 1
        return []