class Solution:
    def minimumRounds(self, a: List[int]) -> int:
        c = Counter(a)
        z = 0
        for i in c:
            if c[i] == 1:
                return -1
            z += (c[i] + 2) // 3
        return z