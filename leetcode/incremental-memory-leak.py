class Solution:
    def memLeak(self, m1: int, m2: int) -> List[int]:
        i = 1
        while True:
            if max(m1, m2) < i:
                return [i, m1, m2]
            if m1 < m2:
                m2 -= i
            else:
                m1 -= i
            i += 1