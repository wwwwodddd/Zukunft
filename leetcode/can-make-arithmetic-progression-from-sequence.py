class Solution:
    def canMakeArithmeticProgression(self, a: List[int]) -> bool:
        a.sort()
        for i in range(1,len(a)):
            if a[i]-a[i-1]!=a[1]-a[0]:
                return False
        return True