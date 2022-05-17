class Solution:
    def toHex(self, num: int) -> str:
        return hex(num%2**32)[2:]