class Solution:
    def advantageCount(self, a: List[int], b: List[int]) -> List[int]:
        n = len(a)
        a = sorted([(a[i], i) for i in range(n)])
        b = sorted([(b[i], i) for i in range(n)])
        c = [0 for i in range(n)]
        l = 0
        r = n - 1
        for i in range(n)[::-1]:
            if a[r][0] > b[i][0]:
                c[b[i][1]] = a[r][0]
                r -= 1
            else:
                c[b[i][1]] = a[l][0]
                l += 1
        return c