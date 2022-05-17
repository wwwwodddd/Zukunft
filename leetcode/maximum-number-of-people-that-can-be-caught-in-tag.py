class Solution:
    def catchMaximumAmountofPeople(self, a: List[int], d: int) -> int:
        p = []
        q = []
        for i in range(len(a)):
            if a[i] == 0:
                p.append(i)
            else:
                q.append(i)
        i = 0
        j = 0
        z = 0
        while i < len(p) and j < len(q):
            if abs(p[i] - q[j]) <= d:
                i += 1
                j += 1
                z += 1
            elif p[i] < q[j]:
                i += 1
            else:
                j += 1
        return z