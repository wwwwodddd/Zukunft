class Solution:
    def subarraysDivByK(self, a: List[int], k: int) -> int:
        s = 0
        c = [0 for i in range(k)]
        c[s] += 1
        z = 0
        for i in a:
            s = (s + i) % k
            z += c[s]
            c[s] += 1
        return z