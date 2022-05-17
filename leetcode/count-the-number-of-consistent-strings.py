class Solution:
    def countConsistentStrings(self, s: str, a: List[str]) -> int:
        s = set(s)
        z = 0
        for i in a:
            if (set(i) & set(s)) == set(i):
                z += 1
        return z