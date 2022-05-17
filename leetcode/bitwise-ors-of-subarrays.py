class Solution:
    def subarrayBitwiseORs(self, a: List[int]) -> int:
        z = set()
        f = set()
        for i in a:
            f = {j | i for j in f} | {i}
            z |= f
        return len(z)