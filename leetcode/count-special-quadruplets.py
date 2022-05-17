class Solution:
    def countQuadruplets(self, a: List[int]) -> int:
        z=0
        for i in range(len(a)):
            for j in range(i+1,len(a)):
                for k in range(j+1,len(a)):
                    for l in range(k+1,len(a)):
                        if a[i]+a[j]+a[k]==a[l]:
                            z+=1
        return z