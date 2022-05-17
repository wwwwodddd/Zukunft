class Solution:
    def decompressRLElist(self, a: List[int]) -> List[int]:
        b = []
        for i in range(0, len(a), 2):
            for j in range(a[i]):
                b.append(a[i + 1])
        return b