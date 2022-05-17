class Solution:
    def minPatches(self, a: List[int], n: int) -> int:
        s = 0
        c = 0
        a.sort()
        i = 0
        a.append(n + 1)
        while s < n:
            if a[i] > s + 1:
                s += s + 1
                c += 1
            else:
                s += a[i]
                i += 1
        return c