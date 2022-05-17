class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        d = minutesToTest // minutesToDie + 1
        c = 0
        while buckets > 1:
            buckets = (buckets + d - 1) // d
            c += 1
        return c