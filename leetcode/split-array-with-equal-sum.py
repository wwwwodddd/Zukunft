class Solution:
    def splitArray(self, a: List[int]) -> bool:
        n = len(a)
        for j in range(3, n - 3):
            v = set()
            i = 0
            x = 0
            y = sum(a[i+1:j])
            while i + 2 < j:
                x += a[i]
                i += 1
                y -= a[i]
                if x == y:
                    v.add(x)
            i = j + 1
            x = 0
            y = sum(a[i+1:])
            while i + 2 < n:
                x += a[i]
                i += 1
                y -= a[i]
                if x == y:
                    if x in v:
                        return True
        return False