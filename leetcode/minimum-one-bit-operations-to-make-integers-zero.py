class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        m = 0
        s = 0
        for i in range(32)[::-1]:
            if n >> i & 1:
                s ^= 1
            m |= s << i
        return m