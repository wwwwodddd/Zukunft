class Solution:
    def numberOfArithmeticSlices(self, a: List[int]) -> int:
        z=0
        c=0
        for i in range(2,len(a)):
            if a[i]-a[i-1]==a[i-1]-a[i-2]:
                c+=1
                z+=c
            else:
                c=0
        return z