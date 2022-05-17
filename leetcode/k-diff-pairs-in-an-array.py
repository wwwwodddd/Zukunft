class Solution:
    def findPairs(self, a: List[int], k: int) -> int:
        c = set()
        z = set()
        for i in sorted(a):
            if i - k in c:
                z.add(i)
            c.add(i)
        return len(z)