class Solution:
    def findComplement(self, n: int) -> int:
        return 2**(len(bin(n))-2)-1-n