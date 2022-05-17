class Solution:
    def maxSatisfaction(self, a: List[int]) -> int:
        a.sort(reverse=True)
        s=0
        z=0
        for i in a:
            s+=i
            if s>0:
                z+=s
        return z