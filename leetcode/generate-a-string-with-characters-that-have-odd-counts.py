class Solution:
    def generateTheString(self, n: int) -> str:
        return (1 - n) % 2 * 'a' + (n - 1 + n % 2) * 'b'