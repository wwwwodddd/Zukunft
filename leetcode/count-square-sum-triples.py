class Solution:
    def countTriples(self, n: int) -> int:
        z=0
        for i in range(1,n+1):
            for j in range(1,n+1):
                sq=int((i*i+j*j)**.5)
                if sq<=n and sq*sq==i*i+j*j:
                    z+=1
        return z