class Solution:
    def arraysIntersection(self, a: List[int], b: List[int], c: List[int]) -> List[int]:
        i = j = k = 0
        d = []
        while i < len(a) and j < len(b) and k < len(c):
            if a[i] == b[j] == c[k]:
                d.append(a[i])
                i += 1
                j += 1
                k += 1
            else:
                mn = min(a[i], b[j], c[k])
                if a[i] == mn:
                    i += 1
                if b[j] == mn:
                    j += 1
                if c[k] == mn:
                    k += 1
        return d