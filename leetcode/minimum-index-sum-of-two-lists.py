class Solution:
    def findRestaurant(self, a: List[str], b: List[str]) -> List[str]:
        z = 2000
        s = []
        for k in set(a) & set(b):
            p = a.index(k) + b.index(k)
            if z > p:
                z = p
                s = [k]
            elif z == p:
                s.append(k)
        return s