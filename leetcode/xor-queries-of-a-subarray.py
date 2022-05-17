class Solution:
    def xorQueries(self, a: List[int], q: List[List[int]]) -> List[int]:
        n = len(a)
        b = [0 for i in range(n + 1)]
        for i in range(n):
            b[i+1] = b[i]^a[i]
        return [b[x]^b[y+1]for x,y in q]