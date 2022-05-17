class Solution:
    def optimalDivision(self, a: List[int]) -> str:
        a=list(map(str,a))
        if len(a)<3:
            return '/'.join(a)
        else:
            return a[0]+'/('+'/'.join(a[1:])+')'