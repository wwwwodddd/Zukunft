class Solution:
    def subarraysWithMoreZerosThanOnes(self, a: List[int]) -> int:
        c = Counter()
        z = s = 0
        c[0] = 1
        t = 0
        for i in a:
            if i == 1:
                t += c[s]
                s += 1
            else:
                s -= 1
                t -= c[s]
            c[s] += 1
            z += t
        return z % 1000000007