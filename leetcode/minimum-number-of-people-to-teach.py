class Solution:
    def minimumTeachings(self, n: int, a: List[List[int]], e: List[List[int]]) -> int:
        a = [set(i)for i in a]
        v = set()
        for x, y in e:
            x -= 1
            y -= 1
            if len(a[x] & a[y]) == 0:
                v.add(x)
                v.add(y)
        c = Counter()
        for i in v:
            for j in a[i]:
                c[j] += 1
        return len(v) - max(c.values()) if v else 0