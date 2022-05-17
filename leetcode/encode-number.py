class Solution:
    def encode(self, n: int) -> str:
        return bin(n + 1)[3:]