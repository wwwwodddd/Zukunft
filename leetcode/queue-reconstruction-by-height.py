class Solution:
    def reconstructQueue(self, a: List[List[int]]) -> List[List[int]]:
        n = len(a)
        a.sort(key=lambda x:(x[0],-x[1]))
        q = [[] for i in range(n)]
        for x, y in a:
            c = 0
            for i in range(n):
                if len(q[i]) == 0:
                    c += 1
                    if c == y + 1:
                        q[i] = [x, y]
                        break
        return q