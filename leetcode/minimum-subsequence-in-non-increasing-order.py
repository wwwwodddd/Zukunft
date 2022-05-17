class Solution:
    def minSubsequence(self, a: List[int]) -> List[int]:
        s=sum(a)
        a.sort(reverse=True)
        z=[]
        for i in a:
            z.append(i)
            s-=2*i
            if s<0:
                break
        return z