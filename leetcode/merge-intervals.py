class Solution:
    def merge(self, a: List[List[int]]) -> List[List[int]]:
        a.sort()
        x, y = a[0]
        re = []
        for l, r in a:
            if y < l:
                re.append((x, y))
                x, y = l, r
            else:
                y = max(y, r)
        re.append((x, y))
        return re