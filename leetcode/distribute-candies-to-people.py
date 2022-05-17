class Solution:
    def distributeCandies(self, m: int, n: int) -> List[int]:
        a=[0 for i in range(n)]
        i=0
        while m>0:
            t=min(i+1,m)
            a[i%n]+=t
            m-=t
            i+=1
        return a