class Solution:
    def countPrefixes(self, w: List[str], s: str) -> int:
        z = 0
        for i in w:
            if s.startswith(i):
                z += 1
        return z