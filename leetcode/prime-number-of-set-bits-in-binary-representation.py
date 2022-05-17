class Solution:
    def countPrimeSetBits(self, l: int, r: int) -> int:
        z=0
        p=[2,3,5,7,11,13,17,19]
        for i in range(l,r+1):
            if bin(i).count('1')in p:
                z+=1
        return z