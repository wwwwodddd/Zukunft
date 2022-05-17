class Solution:
    def findKDistantIndices(self, a: List[int], key: int, k: int) -> List[int]:
        z = []
        for i in range(len(a)):
            if key in a[max(i-k,0):i+1+k]:
                z.append(i)
        return z