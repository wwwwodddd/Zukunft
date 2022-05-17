class Solution:
    def largestDivisibleSubset(self, a: List[int]) -> List[int]:
        a = sorted(a)
        f = [[i] for i in a]
        z=[]
        for i in range(len(a)):
            for j in range(i):
                if a[i]%a[j]==0:
                    if len(f[i])<len(f[j]+[a[i]]):
                        f[i]=f[j]+[a[i]]
            if len(z)<len(f[i]):
                z=f[i]
        return z