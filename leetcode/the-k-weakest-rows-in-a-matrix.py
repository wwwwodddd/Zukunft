class Solution:
    def kWeakestRows(self, a: List[List[int]], k: int) -> List[int]:
        n = len(a)
        m = len(a[0])
        b = sorted((a[i].count(1),i)for i in range(n))
        return [y for x,y in b][:k]