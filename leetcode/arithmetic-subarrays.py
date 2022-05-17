class Solution:
    def checkArithmeticSubarrays(self, a: List[int], l: List[int], r: List[int]) -> List[bool]:
        z = [True for i in l]
        for i in range(len(l)):
            b = a[l[i]:r[i]+1]
            b.sort()
            for j in range(1,len(b)):
                if b[j]-b[j-1] != b[1]-b[0]:
                    z[i] = False
                    break
        return z