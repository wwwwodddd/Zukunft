class Solution:
    def giveGem(self, a: List[int], b: List[List[int]]) -> int:
        for x, y in b:
            t = a[x] // 2
            a[x] -= t
            a[y] += t
        return max(a) - min(a)