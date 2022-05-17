import sortedcontainers
class Solution:
    def getSkyline(self, b: List[List[int]]) -> List[List[int]]:
        a = []
        for x, y, z in b:
            a.append((x, z))
            a.append((y, -z))
        a.sort()
        s = sortedcontainers.SortedList([0])
        z = []
        for x, y in a:
            if y > 0:
                s.add(y)
            else:
                s.remove(-y)
            if len(z) > 0 and z[-1][0] == x:
                z.pop()
            if len(z) == 0 or z[-1][1] != s[-1]:
                z.append((x, s[-1]))
        return z