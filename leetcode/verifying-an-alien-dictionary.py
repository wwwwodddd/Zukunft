class Solution:
    def isAlienSorted(self, a: List[str], r: str) -> bool:
        for i in range(len(a)):
            a[i] = [r.index(j) for j in a[i]]
        return sorted(a) == a