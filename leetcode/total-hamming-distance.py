class Solution:
    def totalHammingDistance(self, a: List[int]) -> int:
        c = [0 for i in range(32)]
        for i in a:
            for j in range(32):
                if i>>j&1:
                    c[j]+=1
        n=len(a)
        z=0
        for i in range(32):
            z+=c[i]*(n-c[i])
        return z