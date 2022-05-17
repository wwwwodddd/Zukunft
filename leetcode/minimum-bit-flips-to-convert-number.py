class Solution:
    def minBitFlips(self, s: int, t: int) -> int:
        return bin(s ^ t).count('1')