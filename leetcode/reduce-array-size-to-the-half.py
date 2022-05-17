class Solution:
    def minSetSize(self, a: List[int]) -> int:
        n=len(a)
        z=0
        for x,y in Counter(a).most_common():
            n-=2*y
            z+=1
            if n<=0:
                break
        return z