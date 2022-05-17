class Solution:
    def intersect(self, a: List[int], b: List[int]) -> List[int]:
        a.sort()
        b.sort()
        c = []
        i = 0
        j = 0
        while i < len(a) and j < len(b):
            if a[i] < b[j]:
                i += 1
            elif a[i] > b[j]:
                j += 1
            else:
                c.append(a[i])
                i += 1
                j += 1
        return c
        