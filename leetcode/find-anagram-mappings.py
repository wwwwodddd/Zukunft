class Solution:
    def anagramMappings(self, a: List[int], b: List[int]) -> List[int]:
        n = len(a)
        a = sorted([(a[i], i) for i in range(n)])
        b = sorted([(b[i], i) for i in range(n)])
        c = [0 for i in range(n)]
        for i in range(n):
            c[a[i][1]] = b[i][1]
        return c