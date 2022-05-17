class Solution:
    def carPooling(self, a: List[List[int]], capacity: int) -> bool:
        b = []
        for x, y, z in a:
            b.append((y, x))
            b.append((z, -x))
        b.sort()
        s = 0
        for x, y in b:
            s += y
            if s > capacity:
                return False
        return True