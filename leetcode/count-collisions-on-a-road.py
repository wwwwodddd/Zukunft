class Solution:
    def countCollisions(self, s: str) -> int:
        return sum(i!='S'for i in s.lstrip('L').rstrip('R'))