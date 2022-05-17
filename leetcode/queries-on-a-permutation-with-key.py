class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        a = list(range(1,m+1))
        z = []
        for q in queries:
            z.append(a.index(q))
            a.remove(q)
            a = [q] + a
        return z