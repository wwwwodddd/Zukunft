class Solution:
    def numOfSubarrays(self, a: List[int]) -> int:
        z=s=0
        c=[1,0]
        for i in a:
            s=(s+i)%2
            z+=c[1-s]
            c[s]+=1
        return z%1000000007