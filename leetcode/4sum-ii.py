class Solution:
    def fourSumCount(self, a: List[int], b: List[int], c: List[int], d: List[int]) -> int:
        f = Counter()
        for i in a:
            for j in b:
                f[i + j] += 1
        z = 0    
        for i in c:
            for j in d:
                z += f[-i - j]
        return z
        