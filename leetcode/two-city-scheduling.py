class Solution:
    def twoCitySchedCost(self, c: List[List[int]]) -> int:
        s = 0
        a = []
        for x, y in c:
            a.append(x - y)
            s += y
        a.sort()
        s += sum(a[:len(c) // 2])
        return s