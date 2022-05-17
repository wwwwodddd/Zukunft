class Solution:
    def minOperations(self, a: List[int]) -> int:
        b = 0
        z = 0
        for i in a:
            z += bin(i).count('1')
            while 2 ** (b + 1) <= i:
                b += 1
        return z + b
        