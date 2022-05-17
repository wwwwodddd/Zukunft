class Solution:
    def circularPermutation(self, n: int, s: int) -> List[int]:
        a = [i ^ i >> 1 for i in range(2 ** n)]
        p = a.index(s)
        return a[p:] + a[:p]