class Solution:
    def maximumBeauty(self, a: List[List[int]], q: List[int]) -> List[int]:
        b = a + [[q[i], 10**10+i]for i in range(len(q))]
        b.sort()
        z = [0 for i in q]
        m = 0
        for x, y in b:
            if y >= 10**10:
                z[y - 10**10] = m
            else:
                m = max(m, y)
        return z