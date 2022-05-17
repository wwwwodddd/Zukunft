class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        a = []
        for i in range(1, 10):
            r = 0
            for j in range(i, 10):
                r = r * 10 + j
                if low <= r <= high:
                    a.append(r)
        return sorted(a)