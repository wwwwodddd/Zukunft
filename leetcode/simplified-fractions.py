class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        z=[]
        for i in range(1,n+1):
            for j in range(1,i):
                if gcd(i,j)==1:
                    z.append('%d/%d'%(j,i))
        return z