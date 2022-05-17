class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        n = sorted(str(n))
        for i in range(34):
            if sorted(str(2 ** i)) == n:
                return True
        return False