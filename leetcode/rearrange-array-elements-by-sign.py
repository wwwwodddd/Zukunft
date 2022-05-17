class Solution:
    def rearrangeArray(self, a: List[int]) -> List[int]:
        b = [i for i in a if i > 0]
        c = [i for i in a if i < 0]
        z = []
        for i, j in zip(b, c):
            z += [i, j]
        return z