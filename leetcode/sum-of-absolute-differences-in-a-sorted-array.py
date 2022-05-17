class Solution:
    def getSumAbsoluteDifferences(self, a: List[int]) -> List[int]:
        n=len(a)
        z=sorted([a[i],i,0]for i in range(n))
        s=sum(a)
        for i in range(n):
            z[i][2]=s+(2*i-n)*(z[i][0])
            s-=2*a[i]
        z=sorted(z,key=lambda x:x[1])
        return [i[2]for i in z]