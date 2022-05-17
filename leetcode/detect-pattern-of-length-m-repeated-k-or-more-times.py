class Solution:
    def containsPattern(self, a: List[int], m: int, k: int) -> bool:
        c = 0
        for i in range(m, len(a)):
            if a[i] == a[i - m]:
                c += 1
                if c == m * (k - 1):
                    return True
            else:
                c = 0
        return False