class Solution:
    def nimGame(self, a: List[int]) -> bool:
        s = 0
        for i in a:
            s ^= i
        return s != 0