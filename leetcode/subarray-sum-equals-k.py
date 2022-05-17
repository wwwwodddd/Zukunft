class Solution:
    def subarraySum(self, a: List[int], k: int) -> int:
        s = 0
        t = Counter()
        t[s] += 1
        z = 0
        for i in a:
            s += i
            z += t[s - k]
            t[s] += 1
        return z
        