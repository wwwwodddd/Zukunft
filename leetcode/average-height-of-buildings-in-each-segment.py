class Solution:
    def averageHeightOfBuildings(self, b: List[List[int]]) -> List[List[int]]:
        e = []
        for x, y, z in b:
            e.append((x, z))
            e.append((y, -z))
        e.sort()
        s = 0
        c = 0
        p = 0
        l = 0
        z = []
        for x, y in e:
            s += y
            if y > 0:
                c += 1
            else:
                c -= 1
            if l > 0 and p < x:
                if z and p == z[-1][1] and l == z[-1][2]:
                    z[-1][1] = x
                else:
                    z.append([p, x, l])
            l = s // max(c, 1)
            p = x
        return z