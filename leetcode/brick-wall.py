class Solution:
    def leastBricks(self, w: List[List[int]]) -> int:
        c = Counter()
        c[0] = 0
        for a in w:
            s = 0
            for i in a[:-1]:
                s += i
                c[s] += 1
        return len(w) - c.most_common(1)[0][1]